#include "Core\MemoryAllocators\StackAllocator.h"

namespace DersEngine
{
	namespace MemoryManagement
	{
		void StackAllocator::Reserve(u32 totalSize)
		{
			if (!m_StartingBlockPtr)
			{
				free(m_StartingBlockPtr);
			}

			m_TotalSize = totalSize;
			m_StartingBlockPtr = malloc(totalSize);
			m_CurrentBlockPtr = m_StartingBlockPtr;
			m_BlockCounter = 0;
		}

		void* StackAllocator::Allocate(u32 size, u32 alignment)
		{
			//void* newTop = AlignData(m_CurrentBlockPtr + m_BlockCounter, alignment);
			

			m_BlockCounter++;
			return nullptr;
		}

		void StackAllocator::Free(void* data)
		{
			m_BlockCounter--;
		}

		void StackAllocator::Destroy()
		{
			free(m_StartingBlockPtr);
			m_StartingBlockPtr = nullptr;
		}
	}
}