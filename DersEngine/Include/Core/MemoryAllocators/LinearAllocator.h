#pragma once

#include <stdlib.h>
#include "MemoryUtil.h"

namespace DersEngine
{
	namespace MemoryManagement
	{
		class LinearAllocator
		{
		private:
			void* m_StartingBlockPtr;
			u64 m_Offset;
			u64 m_TotalSize;

		public:
			void Reserve(u64 totalSize);
			void* Allocate(u64 size, u64 alignment = 0);
			void Free();
			
		};
	}
}
