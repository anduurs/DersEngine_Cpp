#include "Core\MemoryAllocators\StackAllocator.h"

namespace DersEngine
{
	namespace MemoryManagement
	{
		void StackAllocator::Reserve(u64 totalSize)
		{
			if (!m_StartingBlockPtr)
			{
				free(m_StartingBlockPtr);
			}

			m_TotalSize = totalSize;
			m_StartingBlockPtr = malloc(totalSize);
			m_Offset = 0;
		}

		void* StackAllocator::Allocate(u64 size, u64 alignment)
		{
			u64 currentAddress = (u64)m_StartingBlockPtr + m_Offset;
			u64 padding = MemoryUtil::CalculatePaddingWithHeader(currentAddress, alignment, sizeof(Header));

			if (m_Offset + padding + size > m_TotalSize)
			{
				return nullptr;
			}

			m_Offset += padding;

			u64 nextAddress = currentAddress + padding;
			u64 headerAddress = nextAddress - sizeof(Header);

			Header header;
			header.offset = padding;
			Header* headerPtr = (Header*)headerAddress;
			headerPtr = &header;

			m_Offset += size;

			return (void*)nextAddress;
		}

		void StackAllocator::Free(void* blockPtr)
		{
			u64 currentAddress = (u64)blockPtr;
			u64 headerAddress = currentAddress - sizeof(Header);
			Header* header = (Header*)headerAddress;

			m_Offset = currentAddress - header->offset - (u64)m_StartingBlockPtr;
		}

		void StackAllocator::Clear()
		{
			free(m_StartingBlockPtr);
			m_StartingBlockPtr = nullptr;
			m_Offset = 0;
		}
	}
}