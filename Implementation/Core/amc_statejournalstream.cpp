/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Autodesk Inc. nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#include "amc_statejournalstream.hpp"

#include "common_utils.hpp"
#include "common_chrono.hpp"
#include "libmc_interfaceexception.hpp"

#include <iostream>

namespace AMC {

	class CStateJournalStreamChunk
	{
	private:

		uint64_t m_nStartTimeStamp;
		uint64_t m_nStopTimeStamp;

		std::vector<uint8_t> m_Data;

		void writeData(const uint8_t* pData, uint32_t nLength)
		{
			if (pData == nullptr)
				throw ELibMCInterfaceException(LIBMC_ERROR_INVALIDPARAM);

			const uint8_t* pSrc = pData;
			for (uint32_t nIndex = 0; nIndex < nLength; nIndex++) {
				m_Data.push_back(*pSrc);
				pSrc++;
			}
		}

	public:
		CStateJournalStreamChunk(uint64_t nStartTimeStamp)
			: m_nStartTimeStamp (nStartTimeStamp), m_nStopTimeStamp (nStartTimeStamp)
		{

		}

		void writeCommand(const uint32_t nCommand)
		{
			writeData((const uint8_t*)&nCommand, 4);
		}

		void writeUint64(const uint64_t nValue)
		{
			writeData((const uint8_t*)&nValue, 8);
		}

		void writeString(const std::string& sValue)
		{
			uint32_t nLength = (uint32_t)sValue.length();
			writeData((const uint8_t*)&nLength, 4);
			writeData((const uint8_t*) sValue.c_str (), nLength);
		}

		void writeDouble(const uint64_t dValue)
		{
			writeData((const uint8_t*)&dValue, 8);
		}

		void setStopTime(const uint64_t nStopTimeStamp)
		{
			if (nStopTimeStamp < m_nStartTimeStamp)
				throw ELibMCInterfaceException(LIBMC_ERROR_INVALIDTIMESTAMP);

			m_nStopTimeStamp = nStopTimeStamp;

		}

	};

	CStateJournalStream::CStateJournalStream()
		: m_nCurrentTimeStamp (0)
	{

	}

	CStateJournalStream::~CStateJournalStream()
	{

	}

	
	void CStateJournalStream::writeString(const uint32_t nID, const std::string& sValue)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_STRING);
		m_pCurrentChunk->writeString(sValue);
	}


	void CStateJournalStream::startNewChunk()
	{
		m_pCurrentChunk = std::make_shared <CStateJournalStreamChunk>(m_nCurrentTimeStamp);
		m_Chunks.push_back(m_pCurrentChunk);
	}

	void CStateJournalStream::writeTimeStamp(const uint64_t nAbsoluteTimeStamp)
	{
		if (nAbsoluteTimeStamp < m_nCurrentTimeStamp)
			throw ELibMCInterfaceException(LIBMC_ERROR_INVALIDTIMESTAMP);

		uint64_t nDeltaTime = nAbsoluteTimeStamp - m_nCurrentTimeStamp;
		if (nDeltaTime >= STATEJOURNAL_MAXTIMESTAMPDELTA)
			throw ELibMCInterfaceException(LIBMC_ERROR_INVALIDTIMESTAMP);

		m_pCurrentChunk->writeCommand(nDeltaTime | STATEJOURNAL_COMMANDFLAG_TIMESTAMP);
		m_pCurrentChunk->setStopTime(nAbsoluteTimeStamp);

		m_nCurrentTimeStamp = nAbsoluteTimeStamp;
	}

	void CStateJournalStream::writeBool(const uint32_t nID, bool bValue)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		if (bValue) {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_BOOL | STATEJOURNAL_COMMANDFLAG_BOOL_TRUE);
		}
		else {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_BOOL | STATEJOURNAL_COMMANDFLAG_BOOL_FALSE);
		}

	}


	void CStateJournalStream::writeInt64Delta(const uint32_t nID, int64_t nDelta)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		if (nDelta > 0) {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_INTEGER | STATEJOURNAL_COMMANDFLAG_INTEGER_POSITIVE);
			m_pCurrentChunk->writeUint64((uint64_t) nDelta);
		}
		else {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_INTEGER | STATEJOURNAL_COMMANDFLAG_INTEGER_NEGATIVE);
			m_pCurrentChunk->writeUint64((uint64_t)(- nDelta));
		}

	}
	
	void CStateJournalStream::writeDoubleDelta(const uint32_t nID, int64_t nDelta)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		if (nDelta > 0) {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_DOUBLE | STATEJOURNAL_COMMANDFLAG_DOUBLE_POSITIVE);
			m_pCurrentChunk->writeUint64((uint64_t)nDelta);
		}
		else {
			m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_DOUBLE | STATEJOURNAL_COMMANDFLAG_DOUBLE_NEGATIVE);
			m_pCurrentChunk->writeUint64((uint64_t)(-nDelta));
		}

	}


	void CStateJournalStream::writeNameDefinition(const uint32_t nID, const std::string& sName)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_DEFINITION);
		m_pCurrentChunk->writeString(sName);
	}

	void CStateJournalStream::writeUnits(const uint32_t nID, double dUnits)
	{
		if (m_pCurrentChunk == nullptr)
			throw ELibMCInterfaceException(LIBMC_ERROR_NOCURRENTJOURNALCHUNK);

		m_pCurrentChunk->writeCommand(nID | STATEJOURNAL_COMMANDFLAG_UNITS);
		m_pCurrentChunk->writeDouble(dUnits);

	}



}


