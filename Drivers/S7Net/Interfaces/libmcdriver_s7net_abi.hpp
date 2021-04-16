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
 use of MC Driver S7Net 2.0

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_S7NET_HEADER_CPP
#define __LIBMCDRIVER_S7NET_HEADER_CPP

#ifdef __LIBMCDRIVER_S7NET_EXPORTS
#ifdef _WIN32
#define LIBMCDRIVER_S7NET_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define LIBMCDRIVER_S7NET_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __LIBMCDRIVER_S7NET_EXPORTS
#define LIBMCDRIVER_S7NET_DECLSPEC
#endif // __LIBMCDRIVER_S7NET_EXPORTS

#include "libmcdriver_s7net_types.hpp"

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
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_configure(LibMCDriver_S7Net_Driver pDriver, const char * pConfigurationString);

/**
* returns the name identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nNameBufferSize - size of the buffer (including trailing 0)
* @param[out] pNameNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pNameBuffer -  buffer of Name of the driver., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_getname(LibMCDriver_S7Net_Driver pDriver, const LibMCDriver_S7Net_uint32 nNameBufferSize, LibMCDriver_S7Net_uint32* pNameNeededChars, char * pNameBuffer);

/**
* returns the type identifier of the driver
*
* @param[in] pDriver - Driver instance.
* @param[in] nTypeBufferSize - size of the buffer (including trailing 0)
* @param[out] pTypeNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pTypeBuffer -  buffer of Type of the driver., may be NULL
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_gettype(LibMCDriver_S7Net_Driver pDriver, const LibMCDriver_S7Net_uint32 nTypeBufferSize, LibMCDriver_S7Net_uint32* pTypeNeededChars, char * pTypeBuffer);

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
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_getversion(LibMCDriver_S7Net_Driver pDriver, LibMCDriver_S7Net_uint32 * pMajor, LibMCDriver_S7Net_uint32 * pMinor, LibMCDriver_S7Net_uint32 * pMicro, const LibMCDriver_S7Net_uint32 nBuildBufferSize, LibMCDriver_S7Net_uint32* pBuildNeededChars, char * pBuildBuffer);

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
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_getheaderinformation(LibMCDriver_S7Net_Driver pDriver, const LibMCDriver_S7Net_uint32 nNameSpaceBufferSize, LibMCDriver_S7Net_uint32* pNameSpaceNeededChars, char * pNameSpaceBuffer, const LibMCDriver_S7Net_uint32 nBaseNameBufferSize, LibMCDriver_S7Net_uint32* pBaseNameNeededChars, char * pBaseNameBuffer);

/**
* Stores the driver parameters in the driver environment.
*
* @param[in] pDriver - Driver instance.
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_queryparameters(LibMCDriver_S7Net_Driver pDriver);

/*************************************************************************************************************************
 Class definition for PLCCommand
**************************************************************************************************************************/

/**
* Sets an integer parameter of the command
*
* @param[in] pPLCCommand - PLCCommand instance.
* @param[in] pParameterName - Parameter Value
* @param[in] nValue - Parameter Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_plccommand_setintegerparameter(LibMCDriver_S7Net_PLCCommand pPLCCommand, const char * pParameterName, LibMCDriver_S7Net_int32 nValue);

/**
* Sets a string parameter of the command
*
* @param[in] pPLCCommand - PLCCommand instance.
* @param[in] pParameterName - Parameter Value
* @param[in] pValue - Parameter Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_plccommand_setstringparameter(LibMCDriver_S7Net_PLCCommand pPLCCommand, const char * pParameterName, const char * pValue);

/**
* Sets a bool parameter of the command
*
* @param[in] pPLCCommand - PLCCommand instance.
* @param[in] pParameterName - Parameter Value
* @param[in] bValue - Parameter Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_plccommand_setboolparameter(LibMCDriver_S7Net_PLCCommand pPLCCommand, const char * pParameterName, bool bValue);

/**
* Sets a double parameter of the command
*
* @param[in] pPLCCommand - PLCCommand instance.
* @param[in] pParameterName - Parameter Value
* @param[in] dValue - Parameter Value
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_plccommand_setdoubleparameter(LibMCDriver_S7Net_PLCCommand pPLCCommand, const char * pParameterName, LibMCDriver_S7Net_double dValue);

/*************************************************************************************************************************
 Class definition for Driver_S7Net
**************************************************************************************************************************/

/**
* Creates and initializes a new S7 PLC.
*
* @param[in] pDriver_S7Net - Driver_S7Net instance.
* @param[in] eCPUType - S7 CPU Type
* @param[in] pIPAddress - PLC IP Address
* @param[in] nRack - Rack Number
* @param[in] nSlot - Slot Number
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_s7net_connect(LibMCDriver_S7Net_Driver_S7Net pDriver_S7Net, LibMCDriver_S7Net::eS7CPUType eCPUType, const char * pIPAddress, LibMCDriver_S7Net_uint32 nRack, LibMCDriver_S7Net_uint32 nSlot);

/**
* Disconnects from the S7 PLC.
*
* @param[in] pDriver_S7Net - Driver_S7Net instance.
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_s7net_disconnect(LibMCDriver_S7Net_Driver_S7Net pDriver_S7Net);

/**
* Create Command
*
* @param[in] pDriver_S7Net - Driver_S7Net instance.
* @param[in] pCommand - Command to execute
* @param[out] pPLCCommand - Command instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_s7net_createcommand(LibMCDriver_S7Net_Driver_S7Net pDriver_S7Net, const char * pCommand, LibMCDriver_S7Net_PLCCommand * pPLCCommand);

/**
* Execute Command
*
* @param[in] pDriver_S7Net - Driver_S7Net instance.
* @param[in] pPLCCommand - Command instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_s7net_executecommand(LibMCDriver_S7Net_Driver_S7Net pDriver_S7Net, LibMCDriver_S7Net_PLCCommand pPLCCommand);

/**
* Wait for Command to finish executing
*
* @param[in] pDriver_S7Net - Driver_S7Net instance.
* @param[in] pPLCCommand - Command instance
* @param[in] nReactionTimeInMS - How much time the PLC may need to react to the command in Milliseconds. Will fail if no reaction in that time.
* @param[in] nWaitForTimeInMS - How long to wait for the command to be finished in Milliseconds. Will return false if command has not finished.
* @param[out] pCommandSuccess - Returns true if the command was finished successfully.
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_driver_s7net_waitforcommand(LibMCDriver_S7Net_Driver_S7Net pDriver_S7Net, LibMCDriver_S7Net_PLCCommand pPLCCommand, LibMCDriver_S7Net_uint32 nReactionTimeInMS, LibMCDriver_S7Net_uint32 nWaitForTimeInMS, bool * pCommandSuccess);

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
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_getversion(LibMCDriver_S7Net_uint32 * pMajor, LibMCDriver_S7Net_uint32 * pMinor, LibMCDriver_S7Net_uint32 * pMicro);

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
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_getlasterror(LibMCDriver_S7Net_Base pInstance, const LibMCDriver_S7Net_uint32 nErrorMessageBufferSize, LibMCDriver_S7Net_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_releaseinstance(LibMCDriver_S7Net_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_acquireinstance(LibMCDriver_S7Net_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_injectcomponent(const char * pNameSpace, LibMCDriver_S7Net_pvoid pSymbolAddressMethod);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_getsymbollookupmethod(LibMCDriver_S7Net_pvoid * pSymbolLookupMethod);

/**
* Creates a driver instance with a specific name.
*
* @param[in] pName - Name of driver to be created.
* @param[in] pType - Type of driver to be created.
* @param[in] pDriverEnvironment - Environment of this driver.
* @param[out] pInstance - New Driver instance
* @return error code or 0 (success)
*/
LIBMCDRIVER_S7NET_DECLSPEC LibMCDriver_S7NetResult libmcdriver_s7net_createdriver(const char * pName, const char * pType, LibMCEnv_DriverEnvironment pDriverEnvironment, LibMCDriver_S7Net_Driver * pInstance);

#ifdef __cplusplus
}
#endif

#endif // __LIBMCDRIVER_S7NET_HEADER_CPP

