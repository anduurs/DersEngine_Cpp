#pragma once

#include "Core\Types.h"

namespace DersEngine
{
	namespace Memory
	{
		inline void* AlignAddress(const void* memoryAddress, const u64 alignment)
		{
			u64ptr ptr = (u64ptr)memoryAddress;
			u64 mod = ptr % alignment;

			if (mod)
			{
				ptr += alignment - mod;
			}

			return (void*)ptr;
		}

		inline u64 CalculatePadding(const u64 address, const u64 alignment)
		{
			// calculate the memory address which corresponds to the given byte-alignment
			u64 alignedAddress = ((address / alignment) + 1) * alignment;
			// return the difference between the given address and the aligned (the needed padding)
			return alignedAddress - address;
		}

		inline u64 CalculatePaddingWithHeader(const u64 address, const u64 alignment, const u64 headerSize)
		{
			u64 padding = CalculatePadding(address, alignment);
			u64 neededSpace = headerSize;

			if (padding < neededSpace)
			{
				neededSpace -= padding;

				if (neededSpace % alignment > 0)
				{
					padding += alignment * (1 + (neededSpace / alignment));
				}
				else
				{
					padding += alignment * (neededSpace / alignment);
				}
			}

			return padding;
		}
	}
}
