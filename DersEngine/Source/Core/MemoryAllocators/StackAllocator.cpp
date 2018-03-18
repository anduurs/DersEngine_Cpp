#include "Core\MemoryAllocators\StackAllocator.h"

namespace DersEngine
{
	namespace Memory
	{
		void StackAllocator::Init(size_t totalSize)
		{
			if (!m_Data)
			{
				free(m_Data);
			}

			m_TotalSize = totalSize;
			m_Data = malloc(totalSize);
			m_StackPtrOffset = 0;
		}

		void* StackAllocator::Allocate(size_t size)
		{
			if (m_StackPtrOffset >= m_TotalSize)
			{
				return nullptr;
			}

			m_StackPtrOffset++;
			return nullptr;
			//return (void*)&m_Data[m_StackPtrOffset - 1];
		}

		void StackAllocator::Free()
		{
			m_StackPtrOffset--;
		}

		void StackAllocator::Destroy()
		{
			free(m_Data);
			m_Data = nullptr;
		}
	}
}