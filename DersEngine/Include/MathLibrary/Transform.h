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
			Quaternion orientation;
		};

		struct RigidBodyTransform
		{
			Vector3f position;
			Quaternion orientation;
		};
	}
}