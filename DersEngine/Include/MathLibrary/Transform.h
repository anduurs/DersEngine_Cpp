#pragma once

#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"

namespace DersEngine
{
	namespace Maths
	{
		struct Transform
		{
			Vector3f position;
			Vector3f scale;
			Quaternion rotation;
			
			Transform();
			Transform(Vector3f position);
			Transform(Vector3f position, Vector3f scale);
			Transform(Vector3f position, Vector3f scale, Quaternion rotation);
		};
	}
}