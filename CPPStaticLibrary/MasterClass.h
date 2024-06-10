#pragma once

class SomeClass;
class ICallCount;

class MasterClass
{
public:
   MasterClass( ICallCount* callCount );
   ~MasterClass();

   SomeClass* GetSomeClass();

private:
   ICallCount* callCount;//Does not own
   SomeClass* _nativeClass;
};
