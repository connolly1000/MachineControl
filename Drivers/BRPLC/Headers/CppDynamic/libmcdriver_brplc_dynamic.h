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
 use of MC Driver BR Automation 2.0

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_BRPLC_DYNAMICHEADER_CPPTYPES
#define __LIBMCDRIVER_BRPLC_DYNAMICHEADER_CPPTYPES

#include "libmcdriver_brplc_types.hpp"

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
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_ConfigurePtr) (LibMCDriver_BRPLC_Driver pDriver, const char * pConfigurationString);

/**
* returns the name identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nNameBufferSize - size of the buffer (including trailing 0)
* @param[out] pNameNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pNameBuffer -  buffer of Name of the driver., may be NULL
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_GetNamePtr) (LibMCDriver_BRPLC_Driver pDriver, const LibMCDriver_BRPLC_uint32 nNameBufferSize, LibMCDriver_BRPLC_uint32* pNameNeededChars, char * pNameBuffer);

/**
* returns the type identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nTypeBufferSize - size of the buffer (including trailing 0)
* @param[out] pTypeNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pTypeBuffer -  buffer of Type of the driver., may be NULL
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_GetTypePtr) (LibMCDriver_BRPLC_Driver pDriver, const LibMCDriver_BRPLC_uint32 nTypeBufferSize, LibMCDriver_BRPLC_uint32* pTypeNeededChars, char * pTypeBuffer);

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
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_GetVersionPtr) (LibMCDriver_BRPLC_Driver pDriver, LibMCDriver_BRPLC_uint32 * pMajor, LibMCDriver_BRPLC_uint32 * pMinor, LibMCDriver_BRPLC_uint32 * pMicro, const LibMCDriver_BRPLC_uint32 nBuildBufferSize, LibMCDriver_BRPLC_uint32* pBuildNeededChars, char * pBuildBuffer);

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
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_GetHeaderInformationPtr) (LibMCDriver_BRPLC_Driver pDriver, const LibMCDriver_BRPLC_uint32 nNameSpaceBufferSize, LibMCDriver_BRPLC_uint32* pNameSpaceNeededChars, char * pNameSpaceBuffer, const LibMCDriver_BRPLC_uint32 nBaseNameBufferSize, LibMCDriver_BRPLC_uint32* pBaseNameNeededChars, char * pBaseNameBuffer);

/**
* Stores the driver parameters in the driver environment.
*
* @param[in] pDriver - Driver instance.
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCDriver_QueryParametersPtr) (LibMCDriver_BRPLC_Driver pDriver);

/*************************************************************************************************************************
 Class definition for Driver_BRPLC
**************************************************************************************************************************/

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
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCGetVersionPtr) (LibMCDriver_BRPLC_uint32 * pMajor, LibMCDriver_BRPLC_uint32 * pMinor, LibMCDriver_BRPLC_uint32 * pMicro);

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
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCGetLastErrorPtr) (LibMCDriver_BRPLC_Base pInstance, const LibMCDriver_BRPLC_uint32 nErrorMessageBufferSize, LibMCDriver_BRPLC_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCReleaseInstancePtr) (LibMCDriver_BRPLC_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCAcquireInstancePtr) (LibMCDriver_BRPLC_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCInjectComponentPtr) (const char * pNameSpace, LibMCDriver_BRPLC_pvoid pSymbolAddressMethod);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCGetSymbolLookupMethodPtr) (LibMCDriver_BRPLC_pvoid * pSymbolLookupMethod);

/**
* Creates a driver instance with a specific name.
*
* @param[in] pName - Name of driver to be created.
* @param[in] pType - Type of driver to be created.
* @param[in] pDriverEnvironment - Environment of this driver.
* @param[out] pInstance - New Driver instance
* @return error code or 0 (success)
*/
typedef LibMCDriver_BRPLCResult (*PLibMCDriver_BRPLCCreateDriverPtr) (const char * pName, const char * pType, LibMCEnv_DriverEnvironment pDriverEnvironment, LibMCDriver_BRPLC_Driver * pInstance);

/*************************************************************************************************************************
 Function Table Structure
**************************************************************************************************************************/

typedef struct {
	void * m_LibraryHandle;
	PLibMCDriver_BRPLCDriver_ConfigurePtr m_Driver_Configure;
	PLibMCDriver_BRPLCDriver_GetNamePtr m_Driver_GetName;
	PLibMCDriver_BRPLCDriver_GetTypePtr m_Driver_GetType;
	PLibMCDriver_BRPLCDriver_GetVersionPtr m_Driver_GetVersion;
	PLibMCDriver_BRPLCDriver_GetHeaderInformationPtr m_Driver_GetHeaderInformation;
	PLibMCDriver_BRPLCDriver_QueryParametersPtr m_Driver_QueryParameters;
	PLibMCDriver_BRPLCGetVersionPtr m_GetVersion;
	PLibMCDriver_BRPLCGetLastErrorPtr m_GetLastError;
	PLibMCDriver_BRPLCReleaseInstancePtr m_ReleaseInstance;
	PLibMCDriver_BRPLCAcquireInstancePtr m_AcquireInstance;
	PLibMCDriver_BRPLCInjectComponentPtr m_InjectComponent;
	PLibMCDriver_BRPLCGetSymbolLookupMethodPtr m_GetSymbolLookupMethod;
	PLibMCDriver_BRPLCCreateDriverPtr m_CreateDriver;
} sLibMCDriver_BRPLCDynamicWrapperTable;

#endif // __LIBMCDRIVER_BRPLC_DYNAMICHEADER_CPPTYPES

