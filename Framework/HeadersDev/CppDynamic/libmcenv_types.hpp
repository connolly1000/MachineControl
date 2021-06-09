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

Abstract: This is an autogenerated C++-Header file with basic types in
order to allow an easy use of MC Environment Interface

Interface version: 1.0.0

*/

#ifndef __LIBMCENV_TYPES_HEADER_CPP
#define __LIBMCENV_TYPES_HEADER_CPP


/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef LIBMCENV_USELEGACYINTEGERTYPES

typedef unsigned char LibMCEnv_uint8;
typedef unsigned short LibMCEnv_uint16 ;
typedef unsigned int LibMCEnv_uint32;
typedef unsigned long long LibMCEnv_uint64;
typedef char LibMCEnv_int8;
typedef short LibMCEnv_int16;
typedef int LibMCEnv_int32;
typedef long long LibMCEnv_int64;

#else // LIBMCENV_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t LibMCEnv_uint8;
typedef uint16_t LibMCEnv_uint16;
typedef uint32_t LibMCEnv_uint32;
typedef uint64_t LibMCEnv_uint64;
typedef int8_t LibMCEnv_int8;
typedef int16_t LibMCEnv_int16;
typedef int32_t LibMCEnv_int32;
typedef int64_t LibMCEnv_int64 ;

#endif // LIBMCENV_USELEGACYINTEGERTYPES

typedef float LibMCEnv_single;
typedef double LibMCEnv_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef LibMCEnv_int32 LibMCEnvResult;
typedef void * LibMCEnvHandle;
typedef void * LibMCEnv_pvoid;

/*************************************************************************************************************************
 Version for LibMCEnv
**************************************************************************************************************************/

#define LIBMCENV_VERSION_MAJOR 1
#define LIBMCENV_VERSION_MINOR 0
#define LIBMCENV_VERSION_MICRO 0
#define LIBMCENV_VERSION_PRERELEASEINFO ""
#define LIBMCENV_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for LibMCEnv
**************************************************************************************************************************/

#define LIBMCENV_SUCCESS 0
#define LIBMCENV_ERROR_NOTIMPLEMENTED 1
#define LIBMCENV_ERROR_INVALIDPARAM 2
#define LIBMCENV_ERROR_INVALIDCAST 3
#define LIBMCENV_ERROR_BUFFERTOOSMALL 4
#define LIBMCENV_ERROR_GENERICEXCEPTION 5
#define LIBMCENV_ERROR_COULDNOTLOADLIBRARY 6
#define LIBMCENV_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define LIBMCENV_ERROR_INCOMPATIBLEBINARYVERSION 8
#define LIBMCENV_ERROR_PARAMETERGROUPNOTFOUND 9
#define LIBMCENV_ERROR_PARAMETERNOTFOUND 10
#define LIBMCENV_ERROR_COULDNOTFINDSIGNALDEFINITON 11
#define LIBMCENV_ERROR_COULDNOTTRIGGERSIGNAL 12
#define LIBMCENV_ERROR_SIGNALNOTFOUND 13
#define LIBMCENV_ERROR_TERMINATED 14
#define LIBMCENV_ERROR_SIGNALHASTRIGGEREDTWICE 15
#define LIBMCENV_ERROR_SIGNALHASNOTBEENTRIGGERED 16
#define LIBMCENV_ERROR_DRIVERISNOTINITIALISING 17
#define LIBMCENV_ERROR_RESOURCEENTRYNOTFOUND 18
#define LIBMCENV_ERROR_INTERNALERROR 19
#define LIBMCENV_ERROR_INVALIDCHARACTERINFILENAME 20
#define LIBMCENV_ERROR_WORKINGDIRECTORYHASBEENCLEANED 21
#define LIBMCENV_ERROR_INVALIDITERATOR 22
#define LIBMCENV_ERROR_FORMVALUENOTFOUND 23
#define LIBMCENV_ERROR_INVALIDDOUBLEFORMVALUE 24
#define LIBMCENV_ERROR_INVALIDINTEGERFORMVALUE 25

/*************************************************************************************************************************
 Error strings for LibMCEnv
**************************************************************************************************************************/

inline const char * LIBMCENV_GETERRORSTRING (LibMCEnvResult nErrorCode) {
  switch (nErrorCode) {
    case LIBMCENV_SUCCESS: return "no error";
    case LIBMCENV_ERROR_NOTIMPLEMENTED: return "functionality not implemented";
    case LIBMCENV_ERROR_INVALIDPARAM: return "an invalid parameter was passed";
    case LIBMCENV_ERROR_INVALIDCAST: return "a type cast failed";
    case LIBMCENV_ERROR_BUFFERTOOSMALL: return "a provided buffer is too small";
    case LIBMCENV_ERROR_GENERICEXCEPTION: return "a generic exception occurred";
    case LIBMCENV_ERROR_COULDNOTLOADLIBRARY: return "the library could not be loaded";
    case LIBMCENV_ERROR_COULDNOTFINDLIBRARYEXPORT: return "a required exported symbol could not be found in the library";
    case LIBMCENV_ERROR_INCOMPATIBLEBINARYVERSION: return "the version of the binary interface does not match the bindings interface";
    case LIBMCENV_ERROR_PARAMETERGROUPNOTFOUND: return "Parameter group not found";
    case LIBMCENV_ERROR_PARAMETERNOTFOUND: return "Parameter not found";
    case LIBMCENV_ERROR_COULDNOTFINDSIGNALDEFINITON: return "Could not find signal definition";
    case LIBMCENV_ERROR_COULDNOTTRIGGERSIGNAL: return "Could not trigger signal";
    case LIBMCENV_ERROR_SIGNALNOTFOUND: return "Signal not found";
    case LIBMCENV_ERROR_TERMINATED: return "operation has been terminated.";
    case LIBMCENV_ERROR_SIGNALHASTRIGGEREDTWICE: return "signal has been triggered twice.";
    case LIBMCENV_ERROR_SIGNALHASNOTBEENTRIGGERED: return "signal has not been triggered.";
    case LIBMCENV_ERROR_DRIVERISNOTINITIALISING: return "driver is not in initialisation mode.";
    case LIBMCENV_ERROR_RESOURCEENTRYNOTFOUND: return "resource entry not found.";
    case LIBMCENV_ERROR_INTERNALERROR: return "internal error.";
    case LIBMCENV_ERROR_INVALIDCHARACTERINFILENAME: return "invalid character in filename.";
    case LIBMCENV_ERROR_WORKINGDIRECTORYHASBEENCLEANED: return "working directory has been cleaned.";
    case LIBMCENV_ERROR_INVALIDITERATOR: return "invalid iterator.";
    case LIBMCENV_ERROR_FORMVALUENOTFOUND: return "Form value not found.";
    case LIBMCENV_ERROR_INVALIDDOUBLEFORMVALUE: return "Invalid double form value.";
    case LIBMCENV_ERROR_INVALIDINTEGERFORMVALUE: return "Invalid integer form value.";
    default: return "unknown error";
  }
}

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef LibMCEnvHandle LibMCEnv_Base;
typedef LibMCEnvHandle LibMCEnv_Iterator;
typedef LibMCEnvHandle LibMCEnv_ToolpathPart;
typedef LibMCEnvHandle LibMCEnv_ToolpathLayer;
typedef LibMCEnvHandle LibMCEnv_ToolpathAccessor;
typedef LibMCEnvHandle LibMCEnv_Build;
typedef LibMCEnvHandle LibMCEnv_WorkingFileExecution;
typedef LibMCEnvHandle LibMCEnv_WorkingFile;
typedef LibMCEnvHandle LibMCEnv_WorkingFileIterator;
typedef LibMCEnvHandle LibMCEnv_WorkingDirectory;
typedef LibMCEnvHandle LibMCEnv_DriverEnvironment;
typedef LibMCEnvHandle LibMCEnv_SignalTrigger;
typedef LibMCEnvHandle LibMCEnv_SignalHandler;
typedef LibMCEnvHandle LibMCEnv_StateEnvironment;
typedef LibMCEnvHandle LibMCEnv_UIEnvironment;

namespace LibMCEnv {

  /*************************************************************************************************************************
   Declaration of enums
  **************************************************************************************************************************/
  
  enum class eToolpathSegmentType : LibMCEnv_int32 {
    Unknown = 0,
    Hatch = 1,
    Loop = 2,
    Polyline = 3
  };
  
  enum class eToolpathProfileValueType : LibMCEnv_int32 {
    Custom = 0,
    Speed = 1,
    JumpSpeed = 2,
    ExtrusionFactor = 3,
    LaserPower = 4,
    StartDelay = 5,
    EndDelay = 6,
    PolyDelay = 7,
    PolyDelayAngleDependent = 8,
    LaserOnDelay = 9,
    LaserOffDelay = 10,
    JumpDelay = 11,
    MarkDelay = 12,
    LaserFocus = 13
  };
  
  /*************************************************************************************************************************
   Declaration of structs
  **************************************************************************************************************************/
  
  #pragma pack (1)
  
  typedef struct {
      LibMCEnv_int32 m_Coordinates[2];
  } sPosition2D;
  
  typedef struct {
      LibMCEnv_double m_Matrix[3][3];
      LibMCEnv_double m_Translation[3];
  } sToolpathPartTransform;
  
  #pragma pack ()
  
} // namespace LibMCEnv;

// define legacy C-names for enums, structs and function types
typedef LibMCEnv::eToolpathSegmentType eLibMCEnvToolpathSegmentType;
typedef LibMCEnv::eToolpathProfileValueType eLibMCEnvToolpathProfileValueType;
typedef LibMCEnv::sPosition2D sLibMCEnvPosition2D;
typedef LibMCEnv::sToolpathPartTransform sLibMCEnvToolpathPartTransform;

#endif // __LIBMCENV_TYPES_HEADER_CPP
