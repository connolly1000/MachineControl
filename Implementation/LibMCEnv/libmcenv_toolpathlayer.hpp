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


#ifndef __LIBMCENV_TOOLPATHLAYER
#define __LIBMCENV_TOOLPATHLAYER

#include "libmcenv_interfaces.hpp"
#include "amc_toolpathlayerdata.hpp"

// Parent classes
#include "libmcenv_base.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#endif

// Include custom headers here.


namespace LibMCEnv {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CToolpathLayer 
**************************************************************************************************************************/

class CToolpathLayer : public virtual IToolpathLayer, public virtual CBase {
private:

protected:

	AMC::PToolpathLayerData m_pToolpathLayerData;

public:

	CToolpathLayer(AMC::PToolpathLayerData pToolpathLayerData);

	std::string GetLayerDataUUID() override;

	LibMCEnv_uint32 GetSegmentCount() override;

	void GetSegmentInfo(const LibMCEnv_uint32 nIndex, LibMCEnv::eToolpathSegmentType & eType, LibMCEnv_uint32 & nPointCount) override;

	std::string GetSegmentProfileUUID(const LibMCEnv_uint32 nIndex) override;

	std::string GetSegmentPartUUID(const LibMCEnv_uint32 nIndex) override;

	std::string GetSegmentProfileValue(const LibMCEnv_uint32 nIndex, const std::string& sValueName) override;

	LibMCEnv_double GetSegmentProfileTypedValue(const LibMCEnv_uint32 nIndex, const LibMCEnv::eToolpathProfileValueType eValueType) override;

	void GetSegmentPointData(const LibMCEnv_uint32 nIndex, LibMCEnv_uint64 nPointDataBufferSize, LibMCEnv_uint64* pPointDataNeededCount, LibMCEnv::sPosition2D * pPointDataBuffer) override;

	LibMCEnv_int32 GetZValue() override;

	LibMCEnv_double GetUnits() override;

};

} // namespace Impl
} // namespace LibMCEnv

#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif // __LIBMCENV_TOOLPATHLAYER
