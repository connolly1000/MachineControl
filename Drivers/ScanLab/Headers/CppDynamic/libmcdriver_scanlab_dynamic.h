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

#ifndef __LIBMCDRIVER_SCANLAB_DYNAMICHEADER_CPPTYPES
#define __LIBMCDRIVER_SCANLAB_DYNAMICHEADER_CPPTYPES

#include "libmcdriver_scanlab_types.hpp"

#include "libmcenv_types.hpp"


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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ConfigurePtr) (LibMCDriver_ScanLab_Driver pDriver, const char * pConfigurationString);

/**
* returns the name identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nNameBufferSize - size of the buffer (including trailing 0)
* @param[out] pNameNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pNameBuffer -  buffer of Name of the driver., may be NULL
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_GetNamePtr) (LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nNameBufferSize, LibMCDriver_ScanLab_uint32* pNameNeededChars, char * pNameBuffer);

/**
* returns the type identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nTypeBufferSize - size of the buffer (including trailing 0)
* @param[out] pTypeNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pTypeBuffer -  buffer of Type of the driver., may be NULL
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_GetTypePtr) (LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nTypeBufferSize, LibMCDriver_ScanLab_uint32* pTypeNeededChars, char * pTypeBuffer);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_GetVersionPtr) (LibMCDriver_ScanLab_Driver pDriver, LibMCDriver_ScanLab_uint32 * pMajor, LibMCDriver_ScanLab_uint32 * pMinor, LibMCDriver_ScanLab_uint32 * pMicro, const LibMCDriver_ScanLab_uint32 nBuildBufferSize, LibMCDriver_ScanLab_uint32* pBuildNeededChars, char * pBuildBuffer);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_GetHeaderInformationPtr) (LibMCDriver_ScanLab_Driver pDriver, const LibMCDriver_ScanLab_uint32 nNameSpaceBufferSize, LibMCDriver_ScanLab_uint32* pNameSpaceNeededChars, char * pNameSpaceBuffer, const LibMCDriver_ScanLab_uint32 nBaseNameBufferSize, LibMCDriver_ScanLab_uint32* pBaseNameNeededChars, char * pBaseNameBuffer);

/**
* Stores the driver parameters in the driver environment.
*
* @param[in] pDriver - Driver instance.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_QueryParametersPtr) (LibMCDriver_ScanLab_Driver pDriver);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_LoadFirmwarePtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, const char * pFirmwareResource, const char * pFPGAResource, const char * pAuxiliaryResource);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_LoadCorrectionFilePtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nCorrectionFileBufferSize, const LibMCDriver_ScanLab_uint8 * pCorrectionFileBuffer, LibMCDriver_ScanLab_uint32 nTableNumber, LibMCDriver_ScanLab_uint32 nDimension);

/**
* Selects Correction Table on card.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nTableNumberHeadA - Table Number for HeadA (1..8) or off (0).
* @param[in] nTableNumberHeadB - Table Number for HeadA (1..8) or off (0).
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SelectCorrectionTablePtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nTableNumberHeadA, LibMCDriver_ScanLab_uint32 nTableNumberHeadB);

/**
* Configures list buffer size.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nSizeListA - Size of List A
* @param[in] nSizeListB - Size of List B
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_ConfigureListsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nSizeListA, LibMCDriver_ScanLab_uint32 nSizeListB);

/**
* Sets laser mode of card.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] eLaserMode - Laser Mode Enum
* @param[in] eLaserPort - Laser Port Enum
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserModePtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab::eLaserMode eLaserMode, LibMCDriver_ScanLab::eLaserPort eLaserPort);

/**
* Disables automatic laser control.
*
* @param[in] pRTCContext - RTCContext instance.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_DisableAutoLaserControlPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserControlParametersPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, bool bDisableLaser, bool bFinishLaserPulseAfterOn, bool bPhaseShiftOfLaserSignal, bool bLaserOnSignalLowActive, bool bLaserHalfSignalsLowActive, bool bSetDigitalInOneHighActive, bool bOutputSynchronizationActive);

/**
* Sets laser control pulse interval (in 1/64th microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHalfPeriod - Half Output period in 1/64th microseconds
* @param[in] nPulseLength - Pulse Length in 1/64th microseconds
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserPulsesInBitsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nHalfPeriod, LibMCDriver_ScanLab_uint32 nPulseLength);

/**
* Sets laser control pulse interval (in microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dHalfPeriod - Half Output period in microseconds
* @param[in] dPulseLength - Pulse Length in microseconds
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserPulsesInMicroSecondsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dHalfPeriod, LibMCDriver_ScanLab_double dPulseLength);

/**
* Sets standby pulse interval (in 1/64th microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHalfPeriod - Half Output period in 1/64th microseconds
* @param[in] nPulseLength - Pulse Length in 1/64th microseconds
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetStandbyInBitsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nHalfPeriod, LibMCDriver_ScanLab_uint32 nPulseLength);

/**
* Sets laser control pulse interval (in microseconds)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dHalfPeriod - Half Output period in microseconds
* @param[in] dPulseLength - Pulse Length in microseconds
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetStandbyInMicroSecondsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dHalfPeriod, LibMCDriver_ScanLab_double dPulseLength);

/**
* Returns serial number of card
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pSerialNumber - Returns serial number of board.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_GetSerialNumberPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 * pSerialNumber);

/**
* Opens the list to write
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nListIndex - Index of List (1 or 2).
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetStartListPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nListIndex, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Closes the currently open list
*
* @param[in] pRTCContext - RTCContext instance.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetEndOfListPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext);

/**
* Executes the list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nListIndex - Index of List (1 or 2).
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_ExecuteListPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nListIndex, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Sets the AutoChange Position of the currently not running list.
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nPosition - Relative Position in List.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetAutoChangePosPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nPosition);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nMarkDelay - Mark delay in microseconds (MUST be multiple of 10)
* @param[in] nJumpDelay - Jump delay in microseconds (MUST be multiple of 10)
* @param[in] nPolygonDelay - Polygon delay in microseconds (MUST be multiple of 10)
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetDelaysPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nMarkDelay, LibMCDriver_ScanLab_uint32 nJumpDelay, LibMCDriver_ScanLab_uint32 nPolygonDelay);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] dLaserOnDelay - LaserOn delay in microseconds
* @param[in] dLaserOffDelay - LaserOff delay in microseconds
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserDelaysInMicrosecondsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double dLaserOnDelay, LibMCDriver_ScanLab_double dLaserOffDelay);

/**
* Sets the laser delays (on the list)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nLaserOnDelay - LaserOn delay in bits (1/64th microseconds)
* @param[in] nLaserOffDelay - LaserOff delay in bits (1/64th microseconds)
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_SetLaserDelaysInBitsPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nLaserOnDelay, LibMCDriver_ScanLab_uint32 nLaserOffDelay);

/**
* Writes a polyline into the open list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nPointsBufferSize - Number of elements in buffer
* @param[in] pPointsBuffer - Point2D buffer of Points of polyline to draw.
* @param[in] fMarkSpeed - Mark speed in mm/s
* @param[in] fJumpSpeed - Mark speed in mm/s
* @param[in] fPower - Laser power in percent
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_DrawPolylinePtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nPointsBufferSize, const LibMCDriver_ScanLab::sPoint2D * pPointsBuffer, LibMCDriver_ScanLab_single fMarkSpeed, LibMCDriver_ScanLab_single fJumpSpeed, LibMCDriver_ScanLab_single fPower);

/**
* Writes a list of hatches into the open list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nHatchesBufferSize - Number of elements in buffer
* @param[in] pHatchesBuffer - Hatch2D buffer of Hatches to draw.
* @param[in] fMarkSpeed - Mark speed in mm/s
* @param[in] fJumpSpeed - Mark speed in mm/s
* @param[in] fPower - Laser power in percent
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_DrawHatchesPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint64 nHatchesBufferSize, const LibMCDriver_ScanLab::sHatch2D * pHatchesBuffer, LibMCDriver_ScanLab_single fMarkSpeed, LibMCDriver_ScanLab_single fJumpSpeed, LibMCDriver_ScanLab_single fPower);

/**
* Adds a custom delay to the list
*
* @param[in] pRTCContext - RTCContext instance.
* @param[in] nDelay - Custom delay value in microseconds (MUST be multiple of 10)
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_AddCustomDelayPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 nDelay);

/**
* Returns correction factor of Card Calibration (in bits per mm)
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pCorrectionFactor - CorrectionFactor
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_GetCorrectionFactorPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_double * pCorrectionFactor);

/**
* Returns status of list execution
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pBusy - Execution is busy
* @param[out] pPosition - Returns current executed position
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_GetStatusPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, bool * pBusy, LibMCDriver_ScanLab_uint32 * pPosition);

/**
* returns current input list position
*
* @param[in] pRTCContext - RTCContext instance.
* @param[out] pPosition - Returns current position of open list
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCContext_GetInputPointerPtr) (LibMCDriver_ScanLab_RTCContext pRTCContext, LibMCDriver_ScanLab_uint32 * pPosition);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_SearchCardsPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, const char * pIP, const char * pNetmask, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 * pCount);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_SearchCardsByRangePtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, const char * pStartIP, const char * pEndIP, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Returns number of detected Cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[out] pCount - Returns how many cards have been found.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_GetCardCountPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Returns number of found ethernet cards
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[out] pCount - Returns how many ethernet cards have been found.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_GetEthernetCardCountPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 * pCount);

/**
* Acquires a card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nNumber - Number of Card (1-based). Must be between 1 and CardCount.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_AcquireCardPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires a card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nSerialNumber - Desired Serial Number of card.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_AcquireCardBySerialPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nSerialNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires an ethernet card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nNumber - Number of Card (1-based). Must be between 1 and EthernetCardCount.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_AcquireEthernetCardPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

/**
* Acquires an ethernet card and returns an RTCContext instance.
*
* @param[in] pRTCSelector - RTCSelector instance.
* @param[in] nSerialNumber - Desired Serial Number of card.
* @param[out] pInstance - New Context# instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabRTCSelector_AcquireEthernetCardBySerialPtr) (LibMCDriver_ScanLab_RTCSelector pRTCSelector, LibMCDriver_ScanLab_uint32 nSerialNumber, LibMCDriver_ScanLab_RTCContext * pInstance);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_LoadSDKPtr) (LibMCDriver_ScanLab_Driver_ScanLab pDriver_ScanLab, const char * pResourceName);

/**
* Creates and initializes a new RTC selector singleton. Should only be called once per Process.
*
* @param[in] pDriver_ScanLab - Driver_ScanLab instance.
* @param[out] pInstance - New Selector instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_CreateRTCSelectorPtr) (LibMCDriver_ScanLab_Driver_ScanLab pDriver_ScanLab, LibMCDriver_ScanLab_RTCSelector * pInstance);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_RTC5_InitialisePtr) (LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pIP, const char * pNetmask, LibMCDriver_ScanLab_uint32 nTimeout, LibMCDriver_ScanLab_uint32 nSerialNumber);

/**
* Loads the firmware from the driver resources.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] pFirmwareResource - resource name of the firmware program file.
* @param[in] pFPGAResource - resource name of the firmware FPGA file.
* @param[in] pAuxiliaryResource - resource name of the binary auxiliary file.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_RTC5_LoadFirmwarePtr) (LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pFirmwareResource, const char * pFPGAResource, const char * pAuxiliaryResource);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_RTC5_SetCorrectionFilePtr) (LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, LibMCDriver_ScanLab_uint64 nCorrectionFileBufferSize, const LibMCDriver_ScanLab_uint8 * pCorrectionFileBuffer, LibMCDriver_ScanLab_uint32 nTableNumber, LibMCDriver_ScanLab_uint32 nDimension, LibMCDriver_ScanLab_uint32 nTableNumberHeadA, LibMCDriver_ScanLab_uint32 nTableNumberHeadB);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_RTC5_ConfigureLaserModePtr) (LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, LibMCDriver_ScanLab::eLaserMode eLaserMode, LibMCDriver_ScanLab::eLaserPort eLaserPort, LibMCDriver_ScanLab_double dMaxLaserPower, bool bFinishLaserPulseAfterOn, bool bPhaseShiftOfLaserSignal, bool bLaserOnSignalLowActive, bool bLaserHalfSignalsLowActive, bool bSetDigitalInOneHighActive, bool bOutputSynchronizationActive);

/**
* Draws a layer of a build stream. Blocks until the layer is drawn.
*
* @param[in] pDriver_ScanLab_RTC5 - Driver_ScanLab_RTC5 instance.
* @param[in] pStreamUUID - UUID of the build stream. Must have been loaded in memory by the system.
* @param[in] nLayerIndex - Layer index of the build file.
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabDriver_ScanLab_RTC5_DrawLayerPtr) (LibMCDriver_ScanLab_Driver_ScanLab_RTC5 pDriver_ScanLab_RTC5, const char * pStreamUUID, LibMCDriver_ScanLab_uint32 nLayerIndex);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabGetVersionPtr) (LibMCDriver_ScanLab_uint32 * pMajor, LibMCDriver_ScanLab_uint32 * pMinor, LibMCDriver_ScanLab_uint32 * pMicro);

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
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabGetLastErrorPtr) (LibMCDriver_ScanLab_Base pInstance, const LibMCDriver_ScanLab_uint32 nErrorMessageBufferSize, LibMCDriver_ScanLab_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabReleaseInstancePtr) (LibMCDriver_ScanLab_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabAcquireInstancePtr) (LibMCDriver_ScanLab_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabInjectComponentPtr) (const char * pNameSpace, LibMCDriver_ScanLab_pvoid pSymbolAddressMethod);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabGetSymbolLookupMethodPtr) (LibMCDriver_ScanLab_pvoid * pSymbolLookupMethod);

/**
* Creates a driver instance with a specific name.
*
* @param[in] pName - Name of driver to be created.
* @param[in] pType - Type of driver to be created.
* @param[in] pDriverEnvironment - Environment of this driver.
* @param[out] pInstance - New Driver instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_ScanLabResult (*PLibMCDriver_ScanLabCreateDriverPtr) (const char * pName, const char * pType, LibMCEnv_DriverEnvironment pDriverEnvironment, LibMCDriver_ScanLab_Driver * pInstance);

/*************************************************************************************************************************
 Function Table Structure
**************************************************************************************************************************/

typedef struct {
	void * m_LibraryHandle;
	PLibMCDriver_ScanLabDriver_ConfigurePtr m_Driver_Configure;
	PLibMCDriver_ScanLabDriver_GetNamePtr m_Driver_GetName;
	PLibMCDriver_ScanLabDriver_GetTypePtr m_Driver_GetType;
	PLibMCDriver_ScanLabDriver_GetVersionPtr m_Driver_GetVersion;
	PLibMCDriver_ScanLabDriver_GetHeaderInformationPtr m_Driver_GetHeaderInformation;
	PLibMCDriver_ScanLabDriver_QueryParametersPtr m_Driver_QueryParameters;
	PLibMCDriver_ScanLabRTCContext_LoadFirmwarePtr m_RTCContext_LoadFirmware;
	PLibMCDriver_ScanLabRTCContext_LoadCorrectionFilePtr m_RTCContext_LoadCorrectionFile;
	PLibMCDriver_ScanLabRTCContext_SelectCorrectionTablePtr m_RTCContext_SelectCorrectionTable;
	PLibMCDriver_ScanLabRTCContext_ConfigureListsPtr m_RTCContext_ConfigureLists;
	PLibMCDriver_ScanLabRTCContext_SetLaserModePtr m_RTCContext_SetLaserMode;
	PLibMCDriver_ScanLabRTCContext_DisableAutoLaserControlPtr m_RTCContext_DisableAutoLaserControl;
	PLibMCDriver_ScanLabRTCContext_SetLaserControlParametersPtr m_RTCContext_SetLaserControlParameters;
	PLibMCDriver_ScanLabRTCContext_SetLaserPulsesInBitsPtr m_RTCContext_SetLaserPulsesInBits;
	PLibMCDriver_ScanLabRTCContext_SetLaserPulsesInMicroSecondsPtr m_RTCContext_SetLaserPulsesInMicroSeconds;
	PLibMCDriver_ScanLabRTCContext_SetStandbyInBitsPtr m_RTCContext_SetStandbyInBits;
	PLibMCDriver_ScanLabRTCContext_SetStandbyInMicroSecondsPtr m_RTCContext_SetStandbyInMicroSeconds;
	PLibMCDriver_ScanLabRTCContext_GetSerialNumberPtr m_RTCContext_GetSerialNumber;
	PLibMCDriver_ScanLabRTCContext_SetStartListPtr m_RTCContext_SetStartList;
	PLibMCDriver_ScanLabRTCContext_SetEndOfListPtr m_RTCContext_SetEndOfList;
	PLibMCDriver_ScanLabRTCContext_ExecuteListPtr m_RTCContext_ExecuteList;
	PLibMCDriver_ScanLabRTCContext_SetAutoChangePosPtr m_RTCContext_SetAutoChangePos;
	PLibMCDriver_ScanLabRTCContext_SetDelaysPtr m_RTCContext_SetDelays;
	PLibMCDriver_ScanLabRTCContext_SetLaserDelaysInMicrosecondsPtr m_RTCContext_SetLaserDelaysInMicroseconds;
	PLibMCDriver_ScanLabRTCContext_SetLaserDelaysInBitsPtr m_RTCContext_SetLaserDelaysInBits;
	PLibMCDriver_ScanLabRTCContext_DrawPolylinePtr m_RTCContext_DrawPolyline;
	PLibMCDriver_ScanLabRTCContext_DrawHatchesPtr m_RTCContext_DrawHatches;
	PLibMCDriver_ScanLabRTCContext_AddCustomDelayPtr m_RTCContext_AddCustomDelay;
	PLibMCDriver_ScanLabRTCContext_GetCorrectionFactorPtr m_RTCContext_GetCorrectionFactor;
	PLibMCDriver_ScanLabRTCContext_GetStatusPtr m_RTCContext_GetStatus;
	PLibMCDriver_ScanLabRTCContext_GetInputPointerPtr m_RTCContext_GetInputPointer;
	PLibMCDriver_ScanLabRTCSelector_SearchCardsPtr m_RTCSelector_SearchCards;
	PLibMCDriver_ScanLabRTCSelector_SearchCardsByRangePtr m_RTCSelector_SearchCardsByRange;
	PLibMCDriver_ScanLabRTCSelector_GetCardCountPtr m_RTCSelector_GetCardCount;
	PLibMCDriver_ScanLabRTCSelector_GetEthernetCardCountPtr m_RTCSelector_GetEthernetCardCount;
	PLibMCDriver_ScanLabRTCSelector_AcquireCardPtr m_RTCSelector_AcquireCard;
	PLibMCDriver_ScanLabRTCSelector_AcquireCardBySerialPtr m_RTCSelector_AcquireCardBySerial;
	PLibMCDriver_ScanLabRTCSelector_AcquireEthernetCardPtr m_RTCSelector_AcquireEthernetCard;
	PLibMCDriver_ScanLabRTCSelector_AcquireEthernetCardBySerialPtr m_RTCSelector_AcquireEthernetCardBySerial;
	PLibMCDriver_ScanLabDriver_ScanLab_LoadSDKPtr m_Driver_ScanLab_LoadSDK;
	PLibMCDriver_ScanLabDriver_ScanLab_CreateRTCSelectorPtr m_Driver_ScanLab_CreateRTCSelector;
	PLibMCDriver_ScanLabDriver_ScanLab_RTC5_InitialisePtr m_Driver_ScanLab_RTC5_Initialise;
	PLibMCDriver_ScanLabDriver_ScanLab_RTC5_LoadFirmwarePtr m_Driver_ScanLab_RTC5_LoadFirmware;
	PLibMCDriver_ScanLabDriver_ScanLab_RTC5_SetCorrectionFilePtr m_Driver_ScanLab_RTC5_SetCorrectionFile;
	PLibMCDriver_ScanLabDriver_ScanLab_RTC5_ConfigureLaserModePtr m_Driver_ScanLab_RTC5_ConfigureLaserMode;
	PLibMCDriver_ScanLabDriver_ScanLab_RTC5_DrawLayerPtr m_Driver_ScanLab_RTC5_DrawLayer;
	PLibMCDriver_ScanLabGetVersionPtr m_GetVersion;
	PLibMCDriver_ScanLabGetLastErrorPtr m_GetLastError;
	PLibMCDriver_ScanLabReleaseInstancePtr m_ReleaseInstance;
	PLibMCDriver_ScanLabAcquireInstancePtr m_AcquireInstance;
	PLibMCDriver_ScanLabInjectComponentPtr m_InjectComponent;
	PLibMCDriver_ScanLabGetSymbolLookupMethodPtr m_GetSymbolLookupMethod;
	PLibMCDriver_ScanLabCreateDriverPtr m_CreateDriver;
} sLibMCDriver_ScanLabDynamicWrapperTable;

#endif // __LIBMCDRIVER_SCANLAB_DYNAMICHEADER_CPPTYPES

