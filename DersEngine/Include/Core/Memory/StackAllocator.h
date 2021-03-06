#pragma once

/**
	A stack allocator used for managing a chunk of the heap as a Stack structure.
	A pointer is kept to the current memory address and for every allocation this pointer gets incremented.
	When a dealloc occurs the pointer gets decremented.
	Typically used for storing levels/scenes.

@author Anders Eriksson
@version 0.1
*/

#include <stdlib.h>
#include "MemoryUtil.h"

namespace DersEngine
{
	namespace Memory
	{
		class StackAllocator
		{
		private:
			void* m_StartingBlockPtr;
		
			u64 m_Offset;
			u64 m_TotalSize;

			struct Header
			{
				u64 offset;
			};

		public:
			/* Reserves memory on the heap of the size given in bytes */
			void Reserve(u64 totalSize);

			/* Allocates a chunk of memory within this allocator of the size given in bytes. 
			   There is also an option for having the data aligned to a specified byte boundary.
			   @param u64 size the amount of memory in bytes you wish to allocate
			   @param u64 alignment the memory alignment you wish to have for the data. This must be in the power of two (e.g 4byte, 16byte, 32byte alignment). 
			   Default alignment is set to zero.
			*/
			void* Allocate(u64 size, u64 alignment = 0);

			/* Frees the memory that the given data occupies in this allocator */
			void Free(void* blockPtr);

			/* Clears this allocator by freeing all occupied memory */
			void Clear();
			
		};
	}
}