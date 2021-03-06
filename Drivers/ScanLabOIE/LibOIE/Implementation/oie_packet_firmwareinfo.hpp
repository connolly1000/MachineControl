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

#ifndef __AMC_OIE_PACKET_FIRMWAREINFO
#define __AMC_OIE_PACKET_FIRMWAREINFO

#include "oie_packet.hpp"

namespace LibOIE::Impl {
	
	class CPacket_FirmwareInfo : public CPacket {
		protected:

			std::string m_sDeviceName;
			std::string m_sFirmwareName;
			std::string m_sFirmwareVersion;
			std::string m_sFilename;
			uint64_t m_nFileDate;

		public:

			CPacket_FirmwareInfo(uint32_t nSequenceNumber, const std::string& sDeviceName, const std::string& sFirmwareName, const std::string& sFirmwareVersion, const std::string& sFilename, const uint64_t nFileDate);
			CPacket_FirmwareInfo(CPacketReader & pReader);

			virtual ~CPacket_FirmwareInfo();

			virtual void serialize(CPacketWriter& packetWriter) override;

	};
	

	class CPacket_FirmwareInfoRequest : public CPacket_FirmwareInfo {

	protected:

	public:
		CPacket_FirmwareInfoRequest(CPacketReader& pReader);

		virtual ePacketType getType() override;
	};

	class CPacket_FirmwareInfoReply : public CPacket_FirmwareInfo {
		
	protected:
		
	public:
		CPacket_FirmwareInfoReply(CPacketReader& pReader);

		virtual ePacketType getType() override;
	};
	
}


#endif //__AMC_OIE_PACKET_FIRMWAREINFO

