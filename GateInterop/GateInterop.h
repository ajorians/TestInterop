#pragma once

#include "StringHelper.h"
#include <SomeClass.h>
#include <MasterClass.h>
#include <ICallCount.h>

using namespace System;

namespace GateInterop {

	class InterfaceWrapper : public ICallCount
	{
	public:
		InterfaceWrapper(gcroot<InteropDependencies::IManagedCallCount^> managedCallCount)
			: _managedCallCount( managedCallCount )
		{

		}

		int GetAndIncrementCallCount() const
		{
			return _managedCallCount->GetAndIncrementCallCount();
		}

	private:
		gcroot<InteropDependencies::IManagedCallCount^> _managedCallCount;
	};

	public ref class GateClass
	{
	public:
		GateClass( InteropDependencies::IManagedCallCount^ managedCallCount )
			: _interfaceWrapper( new InterfaceWrapper( managedCallCount ) )
			, _masterClass( new MasterClass( _interfaceWrapper ) )
		{
		}
		~GateClass()
		{
			delete _masterClass;
			delete _interfaceWrapper;
		}

		System::String^ GetFromNative()
		{
			using namespace InteropHelper;
			auto* someNativeClass = _masterClass->GetSomeClass();
			return StringConversionHelper::StdStringToSystemString( someNativeClass->GetNativeString() );
		}

	private:
		InterfaceWrapper* _interfaceWrapper;
		MasterClass* _masterClass;
	};
}
