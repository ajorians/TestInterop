#include "pch.h"
#include "MasterClass.h"
#include "SomeClass.h"
#include "ICallCount.h"

MasterClass::MasterClass( ICallCount* callCount )
{
   _nativeClass = new SomeClass( callCount );
}

MasterClass::~MasterClass()
{
   delete _nativeClass;
   _nativeClass = nullptr;
}

SomeClass* MasterClass::GetSomeClass()
{
   return _nativeClass;
}