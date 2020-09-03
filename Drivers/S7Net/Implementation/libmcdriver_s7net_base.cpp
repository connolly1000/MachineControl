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

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Abstract: This is a stub class definition of CBase

*/

#include "libmcdriver_s7net_base.hpp"
#include "libmcdriver_s7net_interfaceexception.hpp"

// Include custom headers here.


using namespace LibMCDriver_S7Net::Impl;

/*************************************************************************************************************************
 Class definition of CBase 
**************************************************************************************************************************/

bool CBase::GetLastErrorMessage(std::string & sErrorMessage)
{
	if (m_pLastError.get() != nullptr) {
		sErrorMessage = *m_pLastError;
		return true;
	} else {
		sErrorMessage = "";
		return false;
	}
}

void CBase::ClearErrorMessages()
{
	m_pLastError.reset();
}

void CBase::RegisterErrorMessage(const std::string & sErrorMessage)
{
	if (m_pLastError.get() == nullptr) {
		m_pLastError.reset(new std::string());
	}
	*m_pLastError = sErrorMessage;
}

void CBase::IncRefCount()
{
	++m_nReferenceCount;
}

bool CBase::DecRefCount()
{
	m_nReferenceCount--;
	if (!m_nReferenceCount) {
		delete this;
		return true;
	}
	return false;
}

