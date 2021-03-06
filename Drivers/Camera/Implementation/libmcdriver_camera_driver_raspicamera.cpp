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


Abstract: This is a stub class definition of CDriver_RaspiCamera

*/

#include "libmcdriver_camera_driver_raspicamera.hpp"
#include "libmcdriver_camera_interfaceexception.hpp"
#include "libmcdriver_camera_raspicameradeviceiterator.hpp"
#include "libmcdriver_camera_pngimage.hpp"

// Include custom headers here.


using namespace LibMCDriver_Camera::Impl;

/*************************************************************************************************************************
 Class definition of CDriver_RaspiCamera 
**************************************************************************************************************************/

CDriver_RaspiCamera::CDriver_RaspiCamera(const std::string& sName, const std::string& sType, LibMCEnv::PDriverEnvironment pDriverEnvironment)
    : CDriver_Camera (sName, sType), m_pDriverEnvironment (pDriverEnvironment)
{
    if (pDriverEnvironment.get() == nullptr)
        throw ELibMCDriver_CameraInterfaceException(LIBMCDRIVER_CAMERA_ERROR_INVALIDPARAM);

}


void CDriver_RaspiCamera::Configure(const std::string& sConfigurationString)
{

}

IRaspiCameraDeviceIterator* CDriver_RaspiCamera::QueryDevices() 
{
    auto pIterator = std::make_unique <CRaspiCameraDeviceIterator> ();
    pIterator->addDevice("/dev/raspicamera0");

    return pIterator.release();
}

void CDriver_RaspiCamera::Initialize(const std::string & sDeviceString, const LibMCDriver_Camera_uint32 nWidth, const LibMCDriver_Camera_uint32 nHeight, const LibMCDriver_Camera::eImagePixelFormat ePixelformat)
{
    // Successful

}

IPNGImage* CDriver_RaspiCamera::CapturePNGImage()
{
    auto pImage = std::make_unique<CPNGImage>(400, 300, eImagePixelFormat::RGB32);

    std::vector <uint8_t>& pData = pImage->getBinaryData();

    pData.push_back('t');
    pData.push_back('e');
    pData.push_back('s');
    pData.push_back('t');
    pData.push_back('1');
    pData.push_back('2');
    pData.push_back('3');

    return pImage.release();
}

void CDriver_RaspiCamera::QueryParameters()
{

}

