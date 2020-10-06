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
 use of S7Net Library Wrapper

Interface version: 1.2.0

*/

#ifndef __LIBS7NET_CPPHEADER_DYNAMIC_CPP
#define __LIBS7NET_CPPHEADER_DYNAMIC_CPP

#include "libs7net_types.hpp"
#include "libs7net_dynamic.h"


#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#endif // _WIN32
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace LibS7Net {

/*************************************************************************************************************************
 Forward Declaration of all classes
**************************************************************************************************************************/
class CWrapper;
class CBase;
class CPLCReadData;
class CPLC;

/*************************************************************************************************************************
 Declaration of deprecated class types
**************************************************************************************************************************/
typedef CWrapper CLibS7NetWrapper;
typedef CBase CLibS7NetBase;
typedef CPLCReadData CLibS7NetPLCReadData;
typedef CPLC CLibS7NetPLC;

/*************************************************************************************************************************
 Declaration of shared pointer types
**************************************************************************************************************************/
typedef std::shared_ptr<CWrapper> PWrapper;
typedef std::shared_ptr<CBase> PBase;
typedef std::shared_ptr<CPLCReadData> PPLCReadData;
typedef std::shared_ptr<CPLC> PPLC;

/*************************************************************************************************************************
 Declaration of deprecated shared pointer types
**************************************************************************************************************************/
typedef PWrapper PLibS7NetWrapper;
typedef PBase PLibS7NetBase;
typedef PPLCReadData PLibS7NetPLCReadData;
typedef PPLC PLibS7NetPLC;


/*************************************************************************************************************************
 classParam Definition
**************************************************************************************************************************/

template<class T> class classParam {
private:
	const T* m_ptr;

public:
	classParam(const T* ptr)
		: m_ptr (ptr)
	{
	}

	classParam(std::shared_ptr <T> sharedPtr)
		: m_ptr (sharedPtr.get())
	{
	}

	LibS7NetHandle GetHandle()
	{
		if (m_ptr != nullptr)
			return m_ptr->handle();
		return nullptr;
	}
};

/*************************************************************************************************************************
 Class ELibS7NetException 
**************************************************************************************************************************/
class ELibS7NetException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibS7NetResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibS7NetException(LibS7NetResult errorCode, const std::string & sErrorMessage)
		: m_errorMessage("LibS7Net Error " + std::to_string(errorCode) + " (" + sErrorMessage + ")")
	{
		m_errorCode = errorCode;
	}

	/**
	* Returns error code
	*/
	LibS7NetResult getErrorCode() const noexcept
	{
		return m_errorCode;
	}

	/**
	* Returns error message
	*/
	const char* what() const noexcept
	{
		return m_errorMessage.c_str();
	}

};

/*************************************************************************************************************************
 Class CInputVector
**************************************************************************************************************************/
template <typename T>
class CInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

// declare deprecated class name
template<typename T>
using CLibS7NetInputVector = CInputVector<T>;

/*************************************************************************************************************************
 Class CWrapper 
**************************************************************************************************************************/
class CWrapper {
public:
	
	CWrapper(void* pSymbolLookupMethod)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTableFromSymbolLookupMethod(&m_WrapperTable, pSymbolLookupMethod));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	CWrapper(const std::string &sFileName)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTable(&m_WrapperTable, sFileName.c_str()));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	static PWrapper loadLibrary(const std::string &sFileName)
	{
		return std::make_shared<CWrapper>(sFileName);
	}
	
	static PWrapper loadLibraryFromSymbolLookupMethod(void* pSymbolLookupMethod)
	{
		return std::make_shared<CWrapper>(pSymbolLookupMethod);
	}
	
	~CWrapper()
	{
		releaseWrapperTable(&m_WrapperTable);
	}
	
	inline void CheckError(CBase * pBaseClass, LibS7NetResult nResult);

	inline void GetVersion(LibS7Net_uint32 & nMajor, LibS7Net_uint32 & nMinor, LibS7Net_uint32 & nMicro);
	inline bool GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage);
	inline void AcquireInstance(classParam<CBase> pInstance);
	inline void ReleaseInstance(classParam<CBase> pInstance);
	inline LibS7Net_pvoid GetSymbolLookupMethod();
	inline PPLC CreatePLC(const std::string & sCOMHost);

private:
	sLibS7NetDynamicWrapperTable m_WrapperTable;
	
	LibS7NetResult checkBinaryVersion()
	{
		LibS7Net_uint32 nMajor, nMinor, nMicro;
		GetVersion(nMajor, nMinor, nMicro);
		if ( (nMajor != LIBS7NET_VERSION_MAJOR) || (nMinor < LIBS7NET_VERSION_MINOR) ) {
			return LIBS7NET_ERROR_INCOMPATIBLEBINARYVERSION;
		}
		return LIBS7NET_SUCCESS;
	}
	LibS7NetResult initWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable);
	LibS7NetResult releaseWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable);
	LibS7NetResult loadWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName);
	LibS7NetResult loadWrapperTableFromSymbolLookupMethod(sLibS7NetDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod);

	friend class CBase;
	friend class CPLCReadData;
	friend class CPLC;

};

	
/*************************************************************************************************************************
 Class CBase 
**************************************************************************************************************************/
class CBase {
public:
	
protected:
	/* Wrapper Object that created the class. */
	CWrapper * m_pWrapper;
	/* Handle to Instance in library*/
	LibS7NetHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(LibS7NetResult nResult)
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->CheckError(this, nResult);
	}
public:
	/**
	* CBase::CBase - Constructor for Base class.
	*/
	CBase(CWrapper * pWrapper, LibS7NetHandle pHandle)
		: m_pWrapper(pWrapper), m_pHandle(pHandle)
	{
	}

	/**
	* CBase::~CBase - Destructor for Base class.
	*/
	virtual ~CBase()
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->ReleaseInstance(this);
		m_pWrapper = nullptr;
	}

	/**
	* CBase::handle - Returns handle to instance.
	*/
	LibS7NetHandle handle() const
	{
		return m_pHandle;
	}

	/**
	* CBase::wrapper - Returns wrapper instance.
	*/
	CWrapper * wrapper() const
	{
		return m_pWrapper;
	}
	
	friend class CWrapper;
};
	
/*************************************************************************************************************************
 Class CPLCReadData 
**************************************************************************************************************************/
class CPLCReadData : public CBase {
public:
	
	/**
	* CPLCReadData::CPLCReadData - Constructor for PLCReadData class.
	*/
	CPLCReadData(CWrapper* pWrapper, LibS7NetHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline void GetData(std::vector<LibS7Net_uint8> & DataBuffer);
};
	
/*************************************************************************************************************************
 Class CPLC 
**************************************************************************************************************************/
class CPLC : public CBase {
public:
	
	/**
	* CPLC::CPLC - Constructor for PLC class.
	*/
	CPLC(CWrapper* pWrapper, LibS7NetHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline void Connect(const eCPUType eCPUType, const std::string & sIP, const LibS7Net_uint32 nRack, const LibS7Net_uint32 nSlot);
	inline bool IsConnected();
	inline bool IsAvailable();
	inline LibS7Net_uint32 GetSlot();
	inline LibS7Net_uint32 GetRack();
	inline eCPUType GetCPUType();
	inline std::string GetIPAddress();
	inline void WriteBytes(const LibS7Net_uint32 nDB, const LibS7Net_uint32 nOffset, const CInputVector<LibS7Net_uint8> & BytesBuffer);
	inline PPLCReadData ReadBytes(const LibS7Net_uint32 nDB, const LibS7Net_uint32 nOffset, const LibS7Net_uint32 nCount);
};
	
	/**
	* CWrapper::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	inline void CWrapper::GetVersion(LibS7Net_uint32 & nMajor, LibS7Net_uint32 & nMinor, LibS7Net_uint32 & nMicro)
	{
		CheckError(nullptr,m_WrapperTable.m_GetVersion(&nMajor, &nMinor, &nMicro));
	}
	
	/**
	* CWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	inline bool CWrapper::GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage)
	{
		LibS7NetHandle hInstance = pInstance.GetHandle();
		LibS7Net_uint32 bytesNeededErrorMessage = 0;
		LibS7Net_uint32 bytesWrittenErrorMessage = 0;
		bool resultHasError = 0;
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, 0, &bytesNeededErrorMessage, nullptr, &resultHasError));
		std::vector<char> bufferErrorMessage(bytesNeededErrorMessage);
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, bytesNeededErrorMessage, &bytesWrittenErrorMessage, &bufferErrorMessage[0], &resultHasError));
		sErrorMessage = std::string(&bufferErrorMessage[0]);
		
		return resultHasError;
	}
	
	/**
	* CWrapper::AcquireInstance - Acquire shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::AcquireInstance(classParam<CBase> pInstance)
	{
		LibS7NetHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_AcquireInstance(hInstance));
	}
	
	/**
	* CWrapper::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::ReleaseInstance(classParam<CBase> pInstance)
	{
		LibS7NetHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_ReleaseInstance(hInstance));
	}
	
	/**
	* CWrapper::GetSymbolLookupMethod - Returns the address of the SymbolLookupMethod
	* @return Address of the SymbolAddressMethod
	*/
	inline LibS7Net_pvoid CWrapper::GetSymbolLookupMethod()
	{
		LibS7Net_pvoid resultSymbolLookupMethod = 0;
		CheckError(nullptr,m_WrapperTable.m_GetSymbolLookupMethod(&resultSymbolLookupMethod));
		
		return resultSymbolLookupMethod;
	}
	
	/**
	* CWrapper::CreatePLC - Returns a PLC instance
	* @param[in] sCOMHost - Path to COM Host
	* @return PLC Instance
	*/
	inline PPLC CWrapper::CreatePLC(const std::string & sCOMHost)
	{
		LibS7NetHandle hPLCInstance = nullptr;
		CheckError(nullptr,m_WrapperTable.m_CreatePLC(sCOMHost.c_str(), &hPLCInstance));
		
		if (!hPLCInstance) {
			CheckError(nullptr,LIBS7NET_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CPLC>(this, hPLCInstance);
	}
	
	inline void CWrapper::CheckError(CBase * pBaseClass, LibS7NetResult nResult)
	{
		if (nResult != 0) {
			std::string sErrorMessage;
			if (pBaseClass != nullptr) {
				GetLastError(pBaseClass, sErrorMessage);
			}
			throw ELibS7NetException(nResult, sErrorMessage);
		}
	}
	

	inline LibS7NetResult CWrapper::initWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		
		pWrapperTable->m_LibraryHandle = nullptr;
		pWrapperTable->m_PLCReadData_GetData = nullptr;
		pWrapperTable->m_PLC_Connect = nullptr;
		pWrapperTable->m_PLC_IsConnected = nullptr;
		pWrapperTable->m_PLC_IsAvailable = nullptr;
		pWrapperTable->m_PLC_GetSlot = nullptr;
		pWrapperTable->m_PLC_GetRack = nullptr;
		pWrapperTable->m_PLC_GetCPUType = nullptr;
		pWrapperTable->m_PLC_GetIPAddress = nullptr;
		pWrapperTable->m_PLC_WriteBytes = nullptr;
		pWrapperTable->m_PLC_ReadBytes = nullptr;
		pWrapperTable->m_GetVersion = nullptr;
		pWrapperTable->m_GetLastError = nullptr;
		pWrapperTable->m_AcquireInstance = nullptr;
		pWrapperTable->m_ReleaseInstance = nullptr;
		pWrapperTable->m_GetSymbolLookupMethod = nullptr;
		pWrapperTable->m_CreatePLC = nullptr;
		
		return LIBS7NET_SUCCESS;
	}

	inline LibS7NetResult CWrapper::releaseWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		
		if (pWrapperTable->m_LibraryHandle != nullptr) {
		#ifdef _WIN32
			HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
			FreeLibrary(hModule);
		#else // _WIN32
			dlclose(pWrapperTable->m_LibraryHandle);
		#endif // _WIN32
			return initWrapperTable(pWrapperTable);
		}
		
		return LIBS7NET_SUCCESS;
	}

	inline LibS7NetResult CWrapper::loadWrapperTable(sLibS7NetDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
	{
		if (pWrapperTable == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		if (pLibraryFileName == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		
		#ifdef _WIN32
		// Convert filename to UTF16-string
		int nLength = (int)strlen(pLibraryFileName);
		int nBufferSize = nLength * 2 + 2;
		std::vector<wchar_t> wsLibraryFileName(nBufferSize);
		int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, &wsLibraryFileName[0], nBufferSize);
		if (nResult == 0)
			return LIBS7NET_ERROR_COULDNOTLOADLIBRARY;
		
		HMODULE hLibrary = LoadLibraryW(wsLibraryFileName.data());
		if (hLibrary == 0) 
			return LIBS7NET_ERROR_COULDNOTLOADLIBRARY;
		#else // _WIN32
		void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
		if (hLibrary == 0) 
			return LIBS7NET_ERROR_COULDNOTLOADLIBRARY;
		dlerror();
		#endif // _WIN32
		
		#ifdef _WIN32
		pWrapperTable->m_PLCReadData_GetData = (PLibS7NetPLCReadData_GetDataPtr) GetProcAddress(hLibrary, "libs7net_plcreaddata_getdata");
		#else // _WIN32
		pWrapperTable->m_PLCReadData_GetData = (PLibS7NetPLCReadData_GetDataPtr) dlsym(hLibrary, "libs7net_plcreaddata_getdata");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLCReadData_GetData == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_Connect = (PLibS7NetPLC_ConnectPtr) GetProcAddress(hLibrary, "libs7net_plc_connect");
		#else // _WIN32
		pWrapperTable->m_PLC_Connect = (PLibS7NetPLC_ConnectPtr) dlsym(hLibrary, "libs7net_plc_connect");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_Connect == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_IsConnected = (PLibS7NetPLC_IsConnectedPtr) GetProcAddress(hLibrary, "libs7net_plc_isconnected");
		#else // _WIN32
		pWrapperTable->m_PLC_IsConnected = (PLibS7NetPLC_IsConnectedPtr) dlsym(hLibrary, "libs7net_plc_isconnected");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_IsConnected == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_IsAvailable = (PLibS7NetPLC_IsAvailablePtr) GetProcAddress(hLibrary, "libs7net_plc_isavailable");
		#else // _WIN32
		pWrapperTable->m_PLC_IsAvailable = (PLibS7NetPLC_IsAvailablePtr) dlsym(hLibrary, "libs7net_plc_isavailable");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_IsAvailable == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_GetSlot = (PLibS7NetPLC_GetSlotPtr) GetProcAddress(hLibrary, "libs7net_plc_getslot");
		#else // _WIN32
		pWrapperTable->m_PLC_GetSlot = (PLibS7NetPLC_GetSlotPtr) dlsym(hLibrary, "libs7net_plc_getslot");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_GetSlot == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_GetRack = (PLibS7NetPLC_GetRackPtr) GetProcAddress(hLibrary, "libs7net_plc_getrack");
		#else // _WIN32
		pWrapperTable->m_PLC_GetRack = (PLibS7NetPLC_GetRackPtr) dlsym(hLibrary, "libs7net_plc_getrack");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_GetRack == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_GetCPUType = (PLibS7NetPLC_GetCPUTypePtr) GetProcAddress(hLibrary, "libs7net_plc_getcputype");
		#else // _WIN32
		pWrapperTable->m_PLC_GetCPUType = (PLibS7NetPLC_GetCPUTypePtr) dlsym(hLibrary, "libs7net_plc_getcputype");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_GetCPUType == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_GetIPAddress = (PLibS7NetPLC_GetIPAddressPtr) GetProcAddress(hLibrary, "libs7net_plc_getipaddress");
		#else // _WIN32
		pWrapperTable->m_PLC_GetIPAddress = (PLibS7NetPLC_GetIPAddressPtr) dlsym(hLibrary, "libs7net_plc_getipaddress");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_GetIPAddress == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_WriteBytes = (PLibS7NetPLC_WriteBytesPtr) GetProcAddress(hLibrary, "libs7net_plc_writebytes");
		#else // _WIN32
		pWrapperTable->m_PLC_WriteBytes = (PLibS7NetPLC_WriteBytesPtr) dlsym(hLibrary, "libs7net_plc_writebytes");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_WriteBytes == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_PLC_ReadBytes = (PLibS7NetPLC_ReadBytesPtr) GetProcAddress(hLibrary, "libs7net_plc_readbytes");
		#else // _WIN32
		pWrapperTable->m_PLC_ReadBytes = (PLibS7NetPLC_ReadBytesPtr) dlsym(hLibrary, "libs7net_plc_readbytes");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_PLC_ReadBytes == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetVersion = (PLibS7NetGetVersionPtr) GetProcAddress(hLibrary, "libs7net_getversion");
		#else // _WIN32
		pWrapperTable->m_GetVersion = (PLibS7NetGetVersionPtr) dlsym(hLibrary, "libs7net_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetVersion == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetLastError = (PLibS7NetGetLastErrorPtr) GetProcAddress(hLibrary, "libs7net_getlasterror");
		#else // _WIN32
		pWrapperTable->m_GetLastError = (PLibS7NetGetLastErrorPtr) dlsym(hLibrary, "libs7net_getlasterror");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetLastError == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AcquireInstance = (PLibS7NetAcquireInstancePtr) GetProcAddress(hLibrary, "libs7net_acquireinstance");
		#else // _WIN32
		pWrapperTable->m_AcquireInstance = (PLibS7NetAcquireInstancePtr) dlsym(hLibrary, "libs7net_acquireinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AcquireInstance == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibS7NetReleaseInstancePtr) GetProcAddress(hLibrary, "libs7net_releaseinstance");
		#else // _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibS7NetReleaseInstancePtr) dlsym(hLibrary, "libs7net_releaseinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ReleaseInstance == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PLibS7NetGetSymbolLookupMethodPtr) GetProcAddress(hLibrary, "libs7net_getsymbollookupmethod");
		#else // _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PLibS7NetGetSymbolLookupMethodPtr) dlsym(hLibrary, "libs7net_getsymbollookupmethod");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetSymbolLookupMethod == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_CreatePLC = (PLibS7NetCreatePLCPtr) GetProcAddress(hLibrary, "libs7net_createplc");
		#else // _WIN32
		pWrapperTable->m_CreatePLC = (PLibS7NetCreatePLCPtr) dlsym(hLibrary, "libs7net_createplc");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_CreatePLC == nullptr)
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		pWrapperTable->m_LibraryHandle = hLibrary;
		return LIBS7NET_SUCCESS;
	}

	inline LibS7NetResult CWrapper::loadWrapperTableFromSymbolLookupMethod(sLibS7NetDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod)
{
		if (pWrapperTable == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		if (pSymbolLookupMethod == nullptr)
			return LIBS7NET_ERROR_INVALIDPARAM;
		
		typedef LibS7NetResult(*SymbolLookupType)(const char*, void**);
		
		SymbolLookupType pLookup = (SymbolLookupType)pSymbolLookupMethod;
		
		LibS7NetResult eLookupError = LIBS7NET_SUCCESS;
		eLookupError = (*pLookup)("libs7net_plcreaddata_getdata", (void**)&(pWrapperTable->m_PLCReadData_GetData));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLCReadData_GetData == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_connect", (void**)&(pWrapperTable->m_PLC_Connect));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_Connect == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_isconnected", (void**)&(pWrapperTable->m_PLC_IsConnected));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_IsConnected == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_isavailable", (void**)&(pWrapperTable->m_PLC_IsAvailable));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_IsAvailable == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_getslot", (void**)&(pWrapperTable->m_PLC_GetSlot));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_GetSlot == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_getrack", (void**)&(pWrapperTable->m_PLC_GetRack));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_GetRack == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_getcputype", (void**)&(pWrapperTable->m_PLC_GetCPUType));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_GetCPUType == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_getipaddress", (void**)&(pWrapperTable->m_PLC_GetIPAddress));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_GetIPAddress == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_writebytes", (void**)&(pWrapperTable->m_PLC_WriteBytes));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_WriteBytes == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_plc_readbytes", (void**)&(pWrapperTable->m_PLC_ReadBytes));
		if ( (eLookupError != 0) || (pWrapperTable->m_PLC_ReadBytes == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_getversion", (void**)&(pWrapperTable->m_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetVersion == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_getlasterror", (void**)&(pWrapperTable->m_GetLastError));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetLastError == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_acquireinstance", (void**)&(pWrapperTable->m_AcquireInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_AcquireInstance == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_releaseinstance", (void**)&(pWrapperTable->m_ReleaseInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_ReleaseInstance == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_getsymbollookupmethod", (void**)&(pWrapperTable->m_GetSymbolLookupMethod));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetSymbolLookupMethod == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libs7net_createplc", (void**)&(pWrapperTable->m_CreatePLC));
		if ( (eLookupError != 0) || (pWrapperTable->m_CreatePLC == nullptr) )
			return LIBS7NET_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		return LIBS7NET_SUCCESS;
}

	
	
	/**
	 * Method definitions for class CBase
	 */
	
	/**
	 * Method definitions for class CPLCReadData
	 */
	
	/**
	* CPLCReadData::GetData - Returns the binary data.
	* @param[out] DataBuffer - Binary data.
	*/
	void CPLCReadData::GetData(std::vector<LibS7Net_uint8> & DataBuffer)
	{
		LibS7Net_uint64 elementsNeededData = 0;
		LibS7Net_uint64 elementsWrittenData = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLCReadData_GetData(m_pHandle, 0, &elementsNeededData, nullptr));
		DataBuffer.resize((size_t) elementsNeededData);
		CheckError(m_pWrapper->m_WrapperTable.m_PLCReadData_GetData(m_pHandle, elementsNeededData, &elementsWrittenData, DataBuffer.data()));
	}
	
	/**
	 * Method definitions for class CPLC
	 */
	
	/**
	* CPLC::Connect - Connects to a PLC Instance
	* @param[in] eCPUType - CPU type to connect to.
	* @param[in] sIP - IP address to connect to.
	* @param[in] nRack - Rack to connect to.
	* @param[in] nSlot - Slot to connect to.
	*/
	void CPLC::Connect(const eCPUType eCPUType, const std::string & sIP, const LibS7Net_uint32 nRack, const LibS7Net_uint32 nSlot)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_Connect(m_pHandle, eCPUType, sIP.c_str(), nRack, nSlot));
	}
	
	/**
	* CPLC::IsConnected - Checks if the socket is connected and polls the other peer (the plc) to see if it is connected.
	* @return Flag if the socket is connected.
	*/
	bool CPLC::IsConnected()
	{
		bool resultConnected = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_IsConnected(m_pHandle, &resultConnected));
		
		return resultConnected;
	}
	
	/**
	* CPLC::IsAvailable - Returns true if a connection to the plc can be established.
	* @return Flag if the socket is connected.
	*/
	bool CPLC::IsAvailable()
	{
		bool resultConnected = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_IsAvailable(m_pHandle, &resultConnected));
		
		return resultConnected;
	}
	
	/**
	* CPLC::GetSlot - Returns slot of the CPU of the plc.
	* @return Slot of the CPU of the plc.
	*/
	LibS7Net_uint32 CPLC::GetSlot()
	{
		LibS7Net_uint32 resultSlot = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_GetSlot(m_pHandle, &resultSlot));
		
		return resultSlot;
	}
	
	/**
	* CPLC::GetRack - Returns rack of the plc.
	* @return Rack of the plc.
	*/
	LibS7Net_uint32 CPLC::GetRack()
	{
		LibS7Net_uint32 resultSlot = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_GetRack(m_pHandle, &resultSlot));
		
		return resultSlot;
	}
	
	/**
	* CPLC::GetCPUType - Returns Cpu type of the plc.
	* @return Cpu type of the plc.
	*/
	eCPUType CPLC::GetCPUType()
	{
		eCPUType resultCPUType = (eCPUType) 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_GetCPUType(m_pHandle, &resultCPUType));
		
		return resultCPUType;
	}
	
	/**
	* CPLC::GetIPAddress - Returns Ip address of the plc.
	* @return Ip address of the plc.
	*/
	std::string CPLC::GetIPAddress()
	{
		LibS7Net_uint32 bytesNeededIPAddress = 0;
		LibS7Net_uint32 bytesWrittenIPAddress = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_GetIPAddress(m_pHandle, 0, &bytesNeededIPAddress, nullptr));
		std::vector<char> bufferIPAddress(bytesNeededIPAddress);
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_GetIPAddress(m_pHandle, bytesNeededIPAddress, &bytesWrittenIPAddress, &bufferIPAddress[0]));
		
		return std::string(&bufferIPAddress[0]);
	}
	
	/**
	* CPLC::WriteBytes - Writes bytes into a PLC DB.
	* @param[in] nDB - ID of DB.
	* @param[in] nOffset - Address to write into.
	* @param[in] BytesBuffer - ByteArray to write.
	*/
	void CPLC::WriteBytes(const LibS7Net_uint32 nDB, const LibS7Net_uint32 nOffset, const CInputVector<LibS7Net_uint8> & BytesBuffer)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_WriteBytes(m_pHandle, nDB, nOffset, (LibS7Net_uint64)BytesBuffer.size(), BytesBuffer.data()));
	}
	
	/**
	* CPLC::ReadBytes - Read bytes from a PLC DB.
	* @param[in] nDB - ID of DB.
	* @param[in] nOffset - Address to write into.
	* @param[in] nCount - Number of bytes to read.
	* @return Read Data Instance.
	*/
	PPLCReadData CPLC::ReadBytes(const LibS7Net_uint32 nDB, const LibS7Net_uint32 nOffset, const LibS7Net_uint32 nCount)
	{
		LibS7NetHandle hReadData = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_PLC_ReadBytes(m_pHandle, nDB, nOffset, nCount, &hReadData));
		
		if (!hReadData) {
			CheckError(LIBS7NET_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CPLCReadData>(m_pWrapper, hReadData);
	}

} // namespace LibS7Net

#endif // __LIBS7NET_CPPHEADER_DYNAMIC_CPP

