#pragma once

#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"

namespace DersEngine
{
	namespace Maths
	{
		struct Transform
		{
			Vec3f position;
			Vec3f scale;
			Quat orientation;
		};

		struct RigidBodyTransform
		{
			Vec3f position;
			Quat orientation;
		};
	}
}