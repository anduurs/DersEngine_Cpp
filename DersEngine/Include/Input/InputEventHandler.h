#pragma once

#include "Core/Types.h"

namespace DersEngine
{
	namespace Input
	{
		class InputEventHandler
		{
		public:
			InputEventHandler();
			virtual ~InputEventHandler();

			virtual void OnKeyDown(u32 keyCode, bool isRepeat) {}
			virtual void OnKeyUp(u32 keyCode, bool isRepeat) {}
			virtual void OnMouseDown(u32 mouseButton, u8 numOfClicks) {}
			virtual void OnMouseUp(u32 mouseButton, u8 numOfClicks) {}
			virtual void OnMouseMove(s32 mouseX, s32 mouseY, s32 deltaX, s32 deltaY) {}
		};
	}
}
