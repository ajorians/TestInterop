// CPPStaticLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include "SomeClass.h"
#include "ICallCount.h"

SomeClass::SomeClass( ICallCount* callCount )
   : _ICallCount( callCount )
{

}

std::string SomeClass::GetNativeString() const
{
   return std::to_string( _ICallCount->GetAndIncrementCallCount() ) + " From C++ :)";
}
