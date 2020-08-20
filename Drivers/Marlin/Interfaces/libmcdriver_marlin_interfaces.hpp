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

Abstract: This is an autogenerated C++ header file in order to allow easy
development of MC Driver Marlin 2.0. The implementer of MC Driver Marlin 2.0 needs to
derive concrete classes from the abstract classes in this header.

Interface version: 1.0.0

*/


#ifndef __LIBMCDRIVER_MARLIN_CPPINTERFACES
#define __LIBMCDRIVER_MARLIN_CPPINTERFACES

#include <string>
#include <memory>

#include "libmcdriver_marlin_types.hpp"


#include "libmcdriverenv_dynamic.hpp"

namespace LibMCDriver_Marlin {
namespace Impl {

/**
 Forward declarations of class interfaces
*/
class IBase;
class IDriver;
class IDriver_Marlin;



/*************************************************************************************************************************
 Parameter Cache definitions
**************************************************************************************************************************/

class ParameterCache {
	public:
		virtual ~ParameterCache() {}
};

template <class T1> class ParameterCache_1 : public ParameterCache {
	private:
		T1 m_param1;
	public:
		ParameterCache_1 (const T1 & param1)
			: m_param1 (param1)
		{
		}

		void retrieveData (T1 & param1)
		{
			param1 = m_param1;
		}
};

template <class T1, class T2> class ParameterCache_2 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
	public:
		ParameterCache_2 (const T1 & param1, const T2 & param2)
			: m_param1 (param1), m_param2 (param2)
		{
		}

		void retrieveData (T1 & param1, T2 & param2)
		{
			param1 = m_param1;
			param2 = m_param2;
		}
};

template <class T1, class T2, class T3> class ParameterCache_3 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
		T3 m_param3;
	public:
		ParameterCache_3 (const T1 & param1, const T2 & param2, const T3 & param3)
			: m_param1 (param1), m_param2 (param2), m_param3 (param3)
		{
		}

		void retrieveData (T1 & param1, T2 & param2, T3 & param3)
		{
			param1 = m_param1;
			param2 = m_param2;
			param3 = m_param3;
		}
};

template <class T1, class T2, class T3, class T4> class ParameterCache_4 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
		T3 m_param3;
		T4 m_param4;
	public:
		ParameterCache_4 (const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4)
			: m_param1 (param1), m_param2 (param2), m_param3 (param3), m_param4 (param4)
		{
		}

		void retrieveData (T1 & param1, T2 & param2, T3 & param3, T4 & param4)
		{
			param1 = m_param1;
			param2 = m_param2;
			param3 = m_param3;
			param4 = m_param4;
		}
};


/*************************************************************************************************************************
 Class interface for Base 
**************************************************************************************************************************/

class IBase {
private:
	std::unique_ptr<ParameterCache> m_ParameterCache;
public:
	/**
	* IBase::~IBase - virtual destructor of IBase
	*/
	virtual ~IBase() {};

	/**
	* IBase::ReleaseBaseClassInterface - Releases ownership of a base class interface. Deletes the reference, if necessary.
	* @param[in] pIBase - The base class instance to release
	*/
	static void ReleaseBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->DecRefCount();
		}
	};

	/**
	* IBase::AcquireBaseClassInterface - Acquires shared ownership of a base class interface.
	* @param[in] pIBase - The base class instance to acquire
	*/
	static void AcquireBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->IncRefCount();
		}
	};


	/**
	* IBase::GetLastErrorMessage - Returns the last error registered of this class instance
	* @param[out] sErrorMessage - Message of the last error registered
	* @return Has an error been registered already
	*/
	virtual bool GetLastErrorMessage(std::string & sErrorMessage) = 0;

	/**
	* IBase::ClearErrorMessages - Clears all registered messages of this class instance
	*/
	virtual void ClearErrorMessages() = 0;

	/**
	* IBase::RegisterErrorMessage - Registers an error message with this class instance
	* @param[in] sErrorMessage - Error message to register
	*/
	virtual void RegisterErrorMessage(const std::string & sErrorMessage) = 0;

	/**
	* IBase::IncRefCount - Increases the reference count of a class instance
	*/
	virtual void IncRefCount() = 0;

	/**
	* IBase::DecRefCount - Decreases the reference count of a class instance and free releases it, if the last reference has been removed
	* @return Has the object been released
	*/
	virtual bool DecRefCount() = 0;

	/**
	* IBase::_setCache - set parameter cache of object
	*/
	void _setCache(ParameterCache * pCache)
	{
		m_ParameterCache.reset(pCache);
	}

	/**
	* IBase::_getCache - returns parameter cache of object
	*/
	ParameterCache* _getCache()
	{
		return m_ParameterCache.get();
	}

};


/**
 Definition of a shared pointer class for IBase
*/
template<class T>
class IBaseSharedPtr : public std::shared_ptr<T>
{
public:
	explicit IBaseSharedPtr(T* t = nullptr)
		: std::shared_ptr<T>(t, IBase::ReleaseBaseClassInterface)
	{
		t->IncRefCount();
	}

	// Reset function, as it also needs to properly set the deleter.
	void reset(T* t = nullptr)
	{
		std::shared_ptr<T>::reset(t, IBase::ReleaseBaseClassInterface);
	}

	// Get-function that increases the Base class's reference count
	T* getCoOwningPtr()
	{
		T* t = this->get();
		t->IncRefCount();
		return t;
	}
};


typedef IBaseSharedPtr<IBase> PIBase;


/*************************************************************************************************************************
 Class interface for Driver 
**************************************************************************************************************************/

class IDriver : public virtual IBase {
public:
	/**
	* IDriver::GetName - returns the name identifier of the driver
	* @return Name of the driver.
	*/
	virtual std::string GetName() = 0;

	/**
	* IDriver::GetType - returns the type identifier of the driver
	* @return Type of the driver.
	*/
	virtual std::string GetType() = 0;

	/**
	* IDriver::GetVersion - returns the version identifiers of the driver
	* @param[out] nMajor - Major version.
	* @param[out] nMinor - Minor version.
	* @param[out] nMicro - Micro version.
	* @param[out] sBuild - Build identifier.
	*/
	virtual void GetVersion(LibMCDriver_Marlin_uint32 & nMajor, LibMCDriver_Marlin_uint32 & nMinor, LibMCDriver_Marlin_uint32 & nMicro, std::string & sBuild) = 0;

	/**
	* IDriver::GetHeaderInformation - returns the header information
	* @param[out] sNameSpace - NameSpace of the driver.
	* @param[out] sBaseName - BaseName of the driver.
	*/
	virtual void GetHeaderInformation(std::string & sNameSpace, std::string & sBaseName) = 0;

};

typedef IBaseSharedPtr<IDriver> PIDriver;


/*************************************************************************************************************************
 Class interface for Driver_Marlin 
**************************************************************************************************************************/

class IDriver_Marlin : public virtual IDriver {
public:
	/**
	* IDriver_Marlin::Connect - Creates and initializes a new Marlin Connector.
	* @param[in] sCOMPort - Device Port to connect to
	* @param[in] nBaudrate - Baudrate to use
	* @param[in] dStatusUpdateInterval - Timer interval [ms] for updating status
	*/
	virtual void Connect(const std::string & sCOMPort, const LibMCDriver_Marlin_uint32 nBaudrate, const LibMCDriver_Marlin_double dStatusUpdateInterval) = 0;

	/**
	* IDriver_Marlin::Disconnect - Disconnects from the Marlin board.
	*/
	virtual void Disconnect() = 0;

	/**
	* IDriver_Marlin::SetAbsolutePositioning - Sets the positioning to absolute values (default true).
	* @param[in] bAbsolute - If true, sets positioning to absolute, if false to relative
	*/
	virtual void SetAbsolutePositioning(const bool bAbsolute) = 0;

	/**
	* IDriver_Marlin::SetHeatedBedTargetTemperature - Sets heated bed target temperature.
	* @param[in] dTemperatureInDegreeCelcius - Bed target temperature.
	*/
	virtual void SetHeatedBedTargetTemperature(const LibMCDriver_Marlin_double dTemperatureInDegreeCelcius) = 0;

	/**
	* IDriver_Marlin::SetExtruderTargetTemperature - Sets target temperature of the given extruder.
	* @param[in] nExtruderID - ID of extruder.
	* @param[in] dTemperatureInDegreeCelcius - Extruder target temperature.
	*/
	virtual void SetExtruderTargetTemperature(const LibMCDriver_Marlin_uint32 nExtruderID, const LibMCDriver_Marlin_double dTemperatureInDegreeCelcius) = 0;

	/**
	* IDriver_Marlin::SetPidParameters - Sets PID parameters.
	* @param[in] dP - New value for P parameter.
	* @param[in] dI - New value for I parameter.
	* @param[in] dD - New value for D parameter.
	*/
	virtual void SetPidParameters(const LibMCDriver_Marlin_double dP, const LibMCDriver_Marlin_double dI, const LibMCDriver_Marlin_double dD) = 0;

	/**
	* IDriver_Marlin::UpdateState - Polls a new state from the firmware.
	*/
	virtual void UpdateState() = 0;

	/**
	* IDriver_Marlin::GetCurrentPosition - Returns the current axis position.
	* @param[out] dX - X Value in mm
	* @param[out] dY - Y Value in mm
	* @param[out] dZ - Z Value in mm
	*/
	virtual void GetCurrentPosition(LibMCDriver_Marlin_double & dX, LibMCDriver_Marlin_double & dY, LibMCDriver_Marlin_double & dZ) = 0;

	/**
	* IDriver_Marlin::GetTargetPosition - Returns the current target position.
	* @param[out] dX - X Value in mm
	* @param[out] dY - Y Value in mm
	* @param[out] dZ - Z Value in mm
	*/
	virtual void GetTargetPosition(LibMCDriver_Marlin_double & dX, LibMCDriver_Marlin_double & dY, LibMCDriver_Marlin_double & dZ) = 0;

	/**
	* IDriver_Marlin::GetExtruderPosition - Returns the current extruder position.
	* @param[out] dE - E Value in mm
	*/
	virtual void GetExtruderPosition(LibMCDriver_Marlin_double & dE) = 0;

	/**
	* IDriver_Marlin::GetHeatedBedTemperature - Returns the current and the target bed temperature.
	* @param[out] dTargetTemperature - Target Temperature in degree celsius.
	* @param[out] dCurrentTemperature - Current Temperature in degree celsius.
	*/
	virtual void GetHeatedBedTemperature(LibMCDriver_Marlin_double & dTargetTemperature, LibMCDriver_Marlin_double & dCurrentTemperature) = 0;

	/**
	* IDriver_Marlin::GetExtruderTemperature - Returns the current and the target temperature of an extruder.
	* @param[in] nExtruderID - ID of Extruder
	* @param[out] dTargetTemperature - Target Temperature in degree celsius.
	* @param[out] dCurrentTemperature - Current Temperature in degree celsius.
	*/
	virtual void GetExtruderTemperature(const LibMCDriver_Marlin_uint32 nExtruderID, LibMCDriver_Marlin_double & dTargetTemperature, LibMCDriver_Marlin_double & dCurrentTemperature) = 0;

	/**
	* IDriver_Marlin::GetPidParameters - Returns the current PID values.
	* @param[out] dP - Current P value.
	* @param[out] dI - Current I value.
	* @param[out] dD - Current D value.
	*/
	virtual void GetPidParameters(LibMCDriver_Marlin_double & dP, LibMCDriver_Marlin_double & dI, LibMCDriver_Marlin_double & dD) = 0;

	/**
	* IDriver_Marlin::CanExecuteMovement - Returns if the movement buffer can receive another movement command..
	* @return True if a MoveTo or MoveFastTo command can be triggered.
	*/
	virtual bool CanExecuteMovement() = 0;

	/**
	* IDriver_Marlin::IsMoving - Returns if the extruder is moving..
	* @return Extruder is moving
	*/
	virtual bool IsMoving() = 0;

	/**
	* IDriver_Marlin::IsHomed - Returns if the printer is homed
	* @return True if printer is homed.
	*/
	virtual bool IsHomed() = 0;

	/**
	* IDriver_Marlin::MoveTo - Moves to/by a certain position by a linear move. Takes the relative/absolute mode into account. Fails if it cannot execute a movement.
	* @param[in] dX - X Value in mm
	* @param[in] dY - Y Value in mm
	* @param[in] dZ - Z Value in mm
	* @param[in] dSpeed - Movement speed in mm/s
	*/
	virtual void MoveTo(const LibMCDriver_Marlin_double dX, const LibMCDriver_Marlin_double dY, const LibMCDriver_Marlin_double dZ, const LibMCDriver_Marlin_double dSpeed) = 0;

	/**
	* IDriver_Marlin::MoveFastTo - Moves to/by a certain position by a fast move. Takes the relative/absolute mode into account. Fails if it cannot execute a movement.
	* @param[in] dX - X Value in mm
	* @param[in] dY - Y Value in mm
	* @param[in] dZ - Z Value in mm
	* @param[in] dSpeed - Movement speed in mm/s
	*/
	virtual void MoveFastTo(const LibMCDriver_Marlin_double dX, const LibMCDriver_Marlin_double dY, const LibMCDriver_Marlin_double dZ, const LibMCDriver_Marlin_double dSpeed) = 0;

	/**
	* IDriver_Marlin::StartHoming - Start Homing of printer.
	*/
	virtual void StartHoming() = 0;

};

typedef IBaseSharedPtr<IDriver_Marlin> PIDriver_Marlin;


/*************************************************************************************************************************
 Global functions declarations
**************************************************************************************************************************/
class CWrapper {
public:
	// Injected Components
	static LibMCDriverEnv::PWrapper sPLibMCDriverEnvWrapper;

	/**
	* Ilibmcdriver_marlin::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	static void GetVersion(LibMCDriver_Marlin_uint32 & nMajor, LibMCDriver_Marlin_uint32 & nMinor, LibMCDriver_Marlin_uint32 & nMicro);

	/**
	* Ilibmcdriver_marlin::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	static bool GetLastError(IBase* pInstance, std::string & sErrorMessage);

	/**
	* Ilibmcdriver_marlin::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void ReleaseInstance(IBase* pInstance);

	/**
	* Ilibmcdriver_marlin::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void AcquireInstance(IBase* pInstance);

	/**
	* Ilibmcdriver_marlin::CreateDriver - Creates a driver instance with a specific name.
	* @param[in] sName - Name of driver to be created.
	* @param[in] sType - Type of driver to be created.
	* @param[in] pDriverEnvironment - Environment of this driver.
	* @return New Driver instance
	*/
	static IDriver * CreateDriver(const std::string & sName, const std::string & sType, LibMCDriverEnv::PDriverEnvironment pDriverEnvironment);

};

LibMCDriver_MarlinResult LibMCDriver_Marlin_GetProcAddress (const char * pProcName, void ** ppProcAddress);

} // namespace Impl
} // namespace LibMCDriver_Marlin

#endif // __LIBMCDRIVER_MARLIN_CPPINTERFACES
