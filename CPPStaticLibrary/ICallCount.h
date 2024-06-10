#pragma once

class ICallCount
{
public:
   virtual ~ICallCount() = default;

   virtual int GetAndIncrementCallCount() const = 0;
};

