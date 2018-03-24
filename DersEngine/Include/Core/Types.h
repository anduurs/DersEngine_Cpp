#pragma once

#include <stdint.h>

namespace DersEngine
{
	/*TYPE, SIZE, RANGE*/

	/* signed char, 1 byte, -128 to 127 */
	using s8 = int8_t;

	/* unsigned char, 1 byte , 0 to 255 */
	using u8 = uint8_t;

	/* short, 2 bytes, -32,768 to 32,767 */
	using s16 = int16_t;

	/* unsigned short, 2 bytes, 0 to 65,535 */
	using u16 = uint16_t;

	/* int, 4 bytes, -2,147,483,648 to 2,147,483,647 */
	using s32 = int32_t;

	/* unsigned int, 4 bytes, 0 to 4,294,967,295 */
	using u32 = uint32_t;

	/* long long, 8 bytes, -(2^63) to (2^63)-1 */
	using s64 = int64_t;

	/* unsigned long long, 8 bytes, 0 to 18,446,744,073,709,551,615 */
	using u64 = uint64_t;

	/* float, 4 bytes */
	using f32 = float;

	/* double, 8 bytes */
	using f64 = double;

	/* unsigned long long, 8bytes */
	/* Any valid pointer to void can be converted to this type 
	* then converted back to pointer to void, 
	* and the result will compare equal to the original pointer */
	using u64ptr = uintptr_t;
}
