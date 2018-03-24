#pragma once

#include "Core\Types.h"

namespace DersEngine
{
	namespace MemoryUtil
	{
		inline void* AlignAddress(void* memoryAddress, u64 alignment)
		{
			u64ptr ptr = (u64ptr)memoryAddress;
			u64 mod = ptr % alignment;

			if (mod)
			{
				ptr += alignment - mod;
			}

			return (void*)ptr;
		}

		inline u64 CalculatePadding(u64 address, u64 alignment)
		{
			// calculate the memory address which corresponds to the given byte-alignment
			u64 alignedAddress = ((address / alignment) + 1) * alignment;
			// return the difference between the given address and the aligned (the needed padding)
			return alignedAddress - address;
		}
	}
}
