using System;

namespace InteropDependencies
{
   public interface IManagedCallCount
   {
      int GetAndIncrementCallCount();
   }
}
