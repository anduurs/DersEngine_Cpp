#pragma once

#include <stdlib.h>

namespace DersEngine
{
	namespace Memory
	{
		template<typename T>
		class StackAllocator
		{
		private:
			T* m_Data;
			unsigned int m_StackPointer;
			size_t m_Size;

		public:
			void Init(size_t size)
			{
				m_Size = size;
				m_Data = (T*) malloc(sizeof(T) * size);
				m_StackPointer = 0;
			}

			T* Allocate()
			{
				if (m_StackPointer >= m_Size)
				{
					return nullptr;
				}
				
				m_StackPointer++;
				return &m_Data[m_StackPointer - 1];
			}

			void Free()
			{
				m_StackPointer--;
			}

			void Destroy()
			{
				free(m_Data);
			}
			
		};
	}
}