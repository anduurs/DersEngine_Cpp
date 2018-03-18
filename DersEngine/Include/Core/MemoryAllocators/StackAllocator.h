#pragma once

#include <stdlib.h>

namespace DersEngine
{
	namespace Memory
	{
		class StackAllocator
		{
		private:
			void* m_Data;
			unsigned int m_StackPtrOffset;
			size_t m_TotalSize;

		public:
			void Init(size_t totalSize);

			void* Allocate(size_t size);

			void Free();

			void Destroy();
			
		};
	}
}