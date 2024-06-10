#pragma once

#include <string>

class ICallCount;

class SomeClass
{
public:
   SomeClass( ICallCount* callCount );

   std::string GetNativeString() const;

private:
   ICallCount* _ICallCount;
};