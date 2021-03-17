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


This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of MC Driver ScanLab RTC5

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_SCANLAB_HEADER_CPP
#define __LIBMCDRIVER_SCANLAB_HEADER_CPP

#ifdef __LIBMCDRIVER_SCANLAB_EXPORTS
#ifdef _WIN32
#define LIBMCDRIVER_SCANLAB_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define LIBMCDRIVER_SCANLAB_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __LIBMCDRIVER_SCANLAB_EXPORTS
#define LIBMCDRIVER_SCANLAB_DECLSPEC
#endif // __LIBMCDRIVER_SCANLAB_EXPORTS

#include "libmcdriver_scanlab_types.hpp"

#include "libmcenv_dynamic.hpp"

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class definition for Driver
**************************************************************************************************************************/

/**
* Configures a driver with its specific configuration data.
*
* @param[in] pDriver - Driver instance.
* @param[in] pConfigurationString - Configuration data of driver.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_configure(LibMCDriver_ScanLab_Driver pDriver, const char * pConfigurationString);

/**
* returns the name identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nNameBufferSize - size of the buffer (including trailing 0)
* @param[out] pNameNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pNameBuffer -  buffer of Name of the driver., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_getname(LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nNameBufferSize, LibMCDriver_ScanLab_uint32* pNameNeededChars, char * pNameBuffer);

/**
* returns the type identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nTypeBufferSize - size of the buffer (including trailing 0)
* @param[out] pTypeNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pTypeBuffer -  buffer of Type of the driver., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_gettype(LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nTypeBufferSize, LibMCDriver_ScanLab_uint32* pTypeNeededChars, char * pTypeBuffer);

/**
* returns the version identifiers of the driver
*
* @param[in] pDriver - Driver instance.
* @param[out] pMajor - Major version.
* @param[out] pMinor - Minor version.
* @param[out] pMicro - Micro version.
* @param[in] nBuildBufferSize - size of the buffer (including trailing 0)
* @param[out] pBuildNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pBuildBuffer -  buffer of Build identifier., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_getversion(LibMCDriver_ScanLab_Driver pDriver, LibMCDriver_ScanLab_uint32 * pMajor, LibMCDriver_ScanLab_uint32 * pMinor, LibMCDriver_ScanLab_uint32 * pMicro, const LibMCDriver_ScanLab_uint32 nBuildBufferSize, LibMCDriver_ScanLab_uint32* pBuildNeededChars, char * pBuildBuffer);

/**
* returns the header information
*
* @param[in] pDriver - Driver instance.
* @param[in] nNameSpaceBufferSize - size of the buffer (including trailing 0)
* @param[out] pNameSpaceNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pNameSpaceBuffer -  buffer of NameSpace of the driver., may be NULL
* @param[in] nBaseNameBufferSize - size of the buffer (including trailing 0)
* @param[out] pBaseNameNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pBaseNameBuffer -  buffer of BaseName of the driver., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_getheaderinformation(LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nNameSpaceBufferSize, LibMCDriver_ScanLab_uint32* pNameSpaceNeededChars, char * pNameSpaceBuffer, const LibMCDriver_ScanLab_uint32 nBaseNameBufferSize, LibMCDriver_ScanLab_uint32* pBaseNameNeededChars, char * pBaseNameBuffer);

/**
* Stores the driver parameters in the driver environment.
*
* @param[in] pDriver - Driver instance.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_queryparameters(LibMCDriver_ScanLab_Driver pDriver);

/*************************************************************************************************************************
 Class definition for RTCContext
**************************************************************************************************************************/

/**
* Loads card firmware from resource files.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] pFirmwareResource - resource name of the firmware program file.
* @param[in] pFPGAResource - resource name of the firmware FPGA file.
* @param[in] pAuxiliaryResource - resource name of the binary auxiliary file.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_loadfirmware(LibMCDriver_ScanLab_RTCContext pRTCContext, const char * pFirmwareResource, const char * pFPGAResource, const char * pAuxiliaryResource);

/**
* Loads card calibration file from given resource file.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nCorrectionFileBufferSize - Number of elements in buffer
* @param[in] pCorrectionFileBuffer - uint8 buffer of binary data of the correction file.
* @param[in] nTableNumber - Correction table index of card (1..8)
* @param[in] nDimension - Is it a 2D or 3D correction file.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_loadcorrectionfile(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nCorrectionFileBufferSize, const LibMCDriver_ScanLab_uint8 * pCorrectionFileBuffer, LibMCDriver_ScanLab_uint32 nTableNumber, LibMCDriver_ScanLab_uint32 nDimension);

/**
* Selects Correction Table on card.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nTableNumberHeadA - Table Number for HeadA (1..8) or off (0).
* @param[in] nTableNumberHeadB - Table Number for HeadA (1..8) or off (0).
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_selectcorrectiontable(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nTableNumberHeadA, LibMCDriver_ScanLab_uint32 nTableNumberHeadB);

/**
* Configures list buffer size.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nSizeListA - Size of List A
* @param[in] nSizeListB - Size of List B
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_configurelists(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nSizeListA, LibMCDriver_ScanLab_uint32 nSizeListB);

/**
* Sets laser mode of card.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] eLaserMode - Laser Mode Enum
* @param[in] eLaserPort - Laser Port Enum
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlasermode(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab::eLaserMode eLaserMode, LibMCDriver_ScanLab::eLaserPort eLaserPort);

/**
* Disables automatic laser control.
*
* @param[in] pRTCContext - RTCContext instance.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_disableautolasercontrol(LibMCDriver_ScanLab_RTCContext pRTCContext);

/**
* Sets laser control parameters of card.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] bDisableLaser - Laser is disabled
* @param[in] bFinishLaserPulseAfterOn - Finish laser pulse after LaserOn
* @param[in] bPhaseShiftOfLaserSignal - 180 degree phase shift of Laser signal
* @param[in] bLaserOnSignalLowActive - Set Laser On Signal Low Active
* @param[in] bLaserHalfSignalsLowActive - Set Laser Half Signal Low Active
* @param[in] bSetDigitalInOneHighActive - Set Digital In 1 high Active
* @param[in] bOutputSynchronizationActive - Output synchronization active
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlasercontrolparameters(LibMCDriver_ScanLab_RTCContext pRTCContext, bool bDisableLaser, bool bFinishLaserPulseAfterOn, bool bPhaseShiftOfLaserSignal, bool bLaserOnSignalLowActive, bool bLaserHalfSignalsLowActive, bool bSetDigitalInOneHighActive, bool bOutputSynchronizationActive);

/**
* Sets laser control pulse interval (in 1/64th microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHalfPeriod - Half Output period in 1/64th microseconds
* @param[in] nPulseLength - Pulse Length in 1/64th microseconds
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlaserpulsesinbits(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nHalfPeriod, LibMCDriver_ScanLab_uint32 nPulseLength);

/**
* Sets laser control pulse interval (in microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dHalfPeriod - Half Output period in microseconds
* @param[in] dPulseLength - Pulse Length in microseconds
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlaserpulsesinmicroseconds(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dHalfPeriod, LibMCDriver_ScanLab_double dPulseLength);

/**
* Sets standby pulse interval (in 1/64th microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHalfPeriod - Half Output period in 1/64th microseconds
* @param[in] nPulseLength - Pulse Length in 1/64th microseconds
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setstandbyinbits(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nHalfPeriod, LibMCDriver_ScanLab_uint32 nPulseLength);

/**
* Sets laser control pulse interval (in microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dHalfPeriod - Half Output period in microseconds
* @param[in] dPulseLength - Pulse Length in microseconds
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setstandbyinmicroseconds(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dHalfPeriod, LibMCDriver_ScanLab_double dPulseLength);

/**
* Returns serial number of card
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pSerialNumber - Returns serial number of board.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getserialnumber(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 * pSerialNumber);

/**
* Opens the list to write
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nListIndex - Index of List (1 or 2).
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setstartlist(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nListIndex, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Closes the currently open list
*
* @param[in] pRTCContext - RTCContext instance.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setendoflist(LibMCDriver_ScanLab_RTCContext pRTCContext);

/**
* Executes the list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nListIndex - Index of List (1 or 2).
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_executelist(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nListIndex, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Sets the AutoChange Position of the currently not running list.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setautochangepos(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nMarkDelay - Mark delay in microseconds (MUST be multiple of 10)
* @param[in] nJumpDelay - Jump delay in microseconds (MUST be multiple of 10)
* @param[in] nPolygonDelay - Polygon delay in microseconds (MUST be multiple of 10)
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setdelays(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nMarkDelay, LibMCDriver_ScanLab_uint32 nJumpDelay, LibMCDriver_ScanLab_uint32 nPolygonDelay);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dLaserOnDelay - LaserOn delay in microseconds
* @param[in] dLaserOffDelay - LaserOff delay in microseconds
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlaserdelaysinmicroseconds(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dLaserOnDelay, LibMCDriver_ScanLab_double dLaserOffDelay);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nLaserOnDelay - LaserOn delay in bits (1/64th microseconds)
* @param[in] nLaserOffDelay - LaserOff delay in bits (1/64th microseconds)
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_setlaserdelaysinbits(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nLaserOnDelay, LibMCDriver_ScanLab_uint32 nLaserOffDelay);

/**
* Writes a polyline into the open list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nPointsBufferSize - Number of elements in buffer
* @param[in] pPointsBuffer - Point2D buffer of Points of polyline to draw.
* @param[in] fMarkSpeed - Mark speed in mm/s
* @param[in] fJumpSpeed - Mark speed in mm/s
* @param[in] fPower - Laser power in percent
* @param[in] fZValue - Focus Z Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_drawpolyline(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nPointsBufferSize, const LibMCDriver_ScanLab::sPoint2D * pPointsBuffer, LibMCDriver_ScanLab_single fMarkSpeed, LibMCDriver_ScanLab_single fJumpSpeed, LibMCDriver_ScanLab_single fPower, LibMCDriver_ScanLab_single fZValue);

/**
* Writes a list of hatches into the open list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHatchesBufferSize - Number of elements in buffer
* @param[in] pHatchesBuffer - Hatch2D buffer of Hatches to draw.
* @param[in] fMarkSpeed - Mark speed in mm/s
* @param[in] fJumpSpeed - Mark speed in mm/s
* @param[in] fPower - Laser power in percent
* @param[in] fZValue - Focus Z Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_drawhatches(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nHatchesBufferSize, const LibMCDriver_ScanLab::sHatch2D * pHatchesBuffer, LibMCDriver_ScanLab_single fMarkSpeed, LibMCDriver_ScanLab_single fJumpSpeed, LibMCDriver_ScanLab_single fPower, LibMCDriver_ScanLab_single fZValue);

/**
* Adds a custom delay to the list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nDelay - Custom delay value in microseconds (MUST be multiple of 10)
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_addcustomdelay(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nDelay);

/**
* Returns correction factor of Card Calibration (in bits per mm)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pCorrectionFactor - CorrectionFactor
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getcorrectionfactor(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double * pCorrectionFactor);

/**
* Returns status of list execution
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pBusy - Execution is busy
* @param[out] pPosition - Returns current executed position
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getstatus(LibMCDriver_ScanLab_RTCContext pRTCContext, bool * pBusy, LibMCDriver_ScanLab_uint32 * pPosition);

/**
* Returns status of scan head
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHeadNo - Head Number
* @param[out] pPositionXisOK - Position X is ok
* @param[out] pPositionYisOK - Position Y is ok
* @param[out] pTemperatureisOK - Temperature is ok
* @param[out] pPowerisOK - Power is ok
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getheadstatus(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nHeadNo, bool * pPositionXisOK, bool * pPositionYisOK, bool * pTemperatureisOK, bool * pPowerisOK);

/**
* Returns status values of scan head
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pLaserIsOn - Laser is on
* @param[out] pPositionX - Current Position X in Units
* @param[out] pPositionY - Current Position Y in Units
* @param[out] pPositionZ - Current Position Z in Units
* @param[out] pCorrectedPositionX - Current Position X in Units
* @param[out] pCorrectedPositionY - Current Position Y in Units
* @param[out] pCorrectedPositionZ - Current Position Z in Units
* @param[out] pFocusShift - Current Focus Shift in Units
* @param[out] pMarkSpeed - Current Mark Speed in Units
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getstatevalues(LibMCDriver_ScanLab_RTCContext pRTCContext, bool * pLaserIsOn, LibMCDriver_ScanLab_uint32 * pPositionX, LibMCDriver_ScanLab_uint32 * pPositionY, LibMCDriver_ScanLab_uint32 * pPositionZ, LibMCDriver_ScanLab_uint32 * pCorrectedPositionX, LibMCDriver_ScanLab_uint32 * pCorrectedPositionY, LibMCDriver_ScanLab_uint32 * pCorrectedPositionZ, LibMCDriver_ScanLab_uint32 * pFocusShift, LibMCDriver_ScanLab_uint32 * pMarkSpeed);

/**
* returns current input list position
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pPosition - Returns current position of open list
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getinputpointer(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 * pPosition);

/**
* Returns version information of the RTC Card
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pRTCVersion - RTC Card Version
* @param[out] pRTCType - RTC Card Type
* @param[out] pDLLVersion - RTC DLL Version
* @param[out] pHEXVersion - RTC HEX Version
* @param[out] pBIOSVersion - RTC BIOS Version
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtccontext_getrtcversion(LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 * pRTCVersion, LibMCDriver_ScanLab_uint32 * pRTCType, LibMCDriver_ScanLab_uint32 * pDLLVersion, LibMCDriver_ScanLab_uint32 * pHEXVersion, LibMCDriver_ScanLab_uint32 * pBIOSVersion);

/*************************************************************************************************************************
 Class definition for RTCSelector
**************************************************************************************************************************/

/**
* Searches Ethernet Cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] pIP - IP Network Address.
* @param[in] pNetmask - IP Netmask Address.
* @param[in] nTimeout - Time out in microseconds.
* @param[out] pCount - Returns how many ethernet cards have been found.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_searchcards(LibMCDriver_ScanLab_RTCSelector pRTCSelector, const char * pIP, const char * pNetmask, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Searches Ethernet Cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] pStartIP - IP Network Address.
* @param[in] pEndIP - IP Network Address.
* @param[in] nTimeout - Time out in microseconds.
* @param[out] pCount - Returns how many ethernet cards have been found.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_searchcardsbyrange(LibMCDriver_ScanLab_RTCSelector pRTCSelector, const char * pStartIP, const char * pEndIP, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Returns number of detected Cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[out] pCount - Returns how many cards have been found.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_getcardcount(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Returns number of found ethernet cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[out] pCount - Returns how many ethernet cards have been found.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_getethernetcardcount(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Acquires a card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nNumber - Number of Card (1-based). Must be between 1 and CardCount.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_acquirecard(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires a card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nSerialNumber - Desired Serial Number of card.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_acquirecardbyserial(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nSerialNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires an ethernet card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nNumber - Number of Card (1-based). Must be between 1 and EthernetCardCount.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_acquireethernetcard(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires an ethernet card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nSerialNumber - Desired Serial Number of card.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_rtcselector_acquireethernetcardbyserial(LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nSerialNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/*************************************************************************************************************************
 Class definition for Driver_ScanLab
**************************************************************************************************************************/

/**
* Initializes the ScanLab SDK.
*
* @param[in] pDriver_ScanLab - Driver_ScanLab instance.
* @param[in] pResourceName - Resource name of Scanlab DLL
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_loadsdk(LibMCDriver_ScanLab_Driver_ScanLab pDriver_ScanLab, const char * pResourceName);

/**
* Creates and initializes a new RTC selector singleton. Should only be called once per Process.
*
* @param[in] pDriver_ScanLab - Driver_ScanLab instance.
* @param[out] pInstance - New Selector instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_creatertcselector(LibMCDriver_ScanLab_Driver_ScanLab pDriver_ScanLab, LibMCDriver_ScanLab_RTCSelector * pInstance);

/*************************************************************************************************************************
 Class definition for Driver_ScanLab_RTC5
**************************************************************************************************************************/

/**
* Initializes the RTC5 Scanner Driver.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] pIP - IP Network Address. Empty string for local card.
* @param[in] pNetmask - IP Netmask Address. Empty string for local card.
* @param[in] nTimeout - Time out in microseconds.
* @param[in] nSerialNumber - Desired Serial Number of card.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_rtc5_initialise(LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pIP, const char * pNetmask, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 nSerialNumber);

/**
* Loads the firmware from the driver resources.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] pFirmwareResource - resource name of the firmware program file.
* @param[in] pFPGAResource - resource name of the firmware FPGA file.
* @param[in] pAuxiliaryResource - resource name of the binary auxiliary file.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_rtc5_loadfirmware(LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pFirmwareResource, const char * pFPGAResource, const char * pAuxiliaryResource);

/**
* Sets the correction file stream.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] nCorrectionFileBufferSize - Number of elements in buffer
* @param[in] pCorrectionFileBuffer - uint8 buffer of binary data of the correction file.
* @param[in] nTableNumber - Correction table index of card (1..8)
* @param[in] nDimension - Is it a 2D or 3D correction file.
* @param[in] nTableNumberHeadA - Table number of Head A.
* @param[in] nTableNumberHeadB - Table number of Head B.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_rtc5_setcorrectionfile(LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, LibMCDriver_ScanLab_uint64 nCorrectionFileBufferSize, const LibMCDriver_ScanLab_uint8 * pCorrectionFileBuffer, LibMCDriver_ScanLab_uint32 nTableNumber, LibMCDriver_ScanLab_uint32 nDimension, LibMCDriver_ScanLab_uint32 nTableNumberHeadA, LibMCDriver_ScanLab_uint32 nTableNumberHeadB);

/**
* Configures the laser mode.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] eLaserMode - Laser Mode Enum
* @param[in] eLaserPort - Laser Port Enum
* @param[in] dMaxLaserPower - Maximum laser power.
* @param[in] bFinishLaserPulseAfterOn - Finish laser pulse after LaserOn
* @param[in] bPhaseShiftOfLaserSignal - 180 degree phase shift of Laser signal
* @param[in] bLaserOnSignalLowActive - Set Laser On Signal Low Active
* @param[in] bLaserHalfSignalsLowActive - Set Laser Half Signal Low Active
* @param[in] bSetDigitalInOneHighActive - Set Digital In 1 high Active
* @param[in] bOutputSynchronizationActive - Output synchronization active
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_rtc5_configurelasermode(LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, LibMCDriver_ScanLab::eLaserMode eLaserMode, LibMCDriver_ScanLab::eLaserPort eLaserPort, LibMCDriver_ScanLab_double dMaxLaserPower, bool bFinishLaserPulseAfterOn, bool bPhaseShiftOfLaserSignal, bool bLaserOnSignalLowActive, bool bLaserHalfSignalsLowActive, bool bSetDigitalInOneHighActive, bool bOutputSynchronizationActive);

/**
* Draws a layer of a build stream. Blocks until the layer is drawn.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] pStreamUUID - UUID of the build stream. Must have been loaded in memory by the system.
* @param[in] nLayerIndex - Layer index of the build file.
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_driver_scanlab_rtc5_drawlayer(LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pStreamUUID, LibMCDriver_ScanLab_uint32 nLayerIndex);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_getversion(LibMCDriver_ScanLab_uint32 * pMajor, LibMCDriver_ScanLab_uint32 * pMinor, LibMCDriver_ScanLab_uint32 * pMicro);

/**
* Returns the last error recorded on this object
*
* @param[in] pInstance - Instance Handle
* @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
* @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
* @param[out] pHasError - Is there a last error to query
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_getlasterror(LibMCDriver_ScanLab_Base pInstance, const LibMCDriver_ScanLab_uint32 nErrorMessageBufferSize, LibMCDriver_ScanLab_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_releaseinstance(LibMCDriver_ScanLab_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_acquireinstance(LibMCDriver_ScanLab_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_injectcomponent(const char * pNameSpace, LibMCDriver_ScanLab_pvoid pSymbolAddressMethod);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_getsymbollookupmethod(LibMCDriver_ScanLab_pvoid * pSymbolLookupMethod);

/**
* Creates a driver instance with a specific name.
*
* @param[in] pName - Name of driver to be created.
* @param[in] pType - Type of driver to be created.
* @param[in] pDriverEnvironment - Environment of this driver.
* @param[out] pInstance - New Driver instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_SCANLAB_DECLSPEC LibMCDriver_ScanLabResult libmcdriver_scanlab_createdriver(const char * pName, const char * pType, LibMCEnv_DriverEnvironment pDriverEnvironment, LibMCDriver_ScanLab_Driver * pInstance);

#ifdef __cplusplus
}
#endif

#endif // __LIBMCDRIVER_SCANLAB_HEADER_CPP

