#include "Core\MemoryAllocators\LinearAllocator.h"
#include <iostream>

namespace DersEngine
{
	namespace MemoryManagement
	{
		void LinearAllocator::Reserve(u64 totalSize)
		{
			m_StartingBlockPtr = malloc(totalSize);
			m_TotalSize = totalSize;
			m_Offset = 0;
		}

		void* LinearAllocator::Allocate(u64 size, u64 alignment)
		{
			u64 currentAddress = (u64)m_StartingBlockPtr + m_Offset;
			u64 padding = 0;

			if (alignment != 0 && m_Offset % alignment != 0)
			{
				padding = MemoryUtil::CalculatePadding(currentAddress, alignment);
			}
			
			if (m_Offset + padding + size > m_TotalSize)
			{
				return nullptr;
			}

			u64 nextAddress = currentAddress + size;
			m_Offset += padding;
			m_Offset += size;

			return (void*)nextAddress;
		}

		void LinearAllocator::Clear()
		{
			free(m_StartingBlockPtr);
			m_StartingBlockPtr = nullptr;
		}
	}
}