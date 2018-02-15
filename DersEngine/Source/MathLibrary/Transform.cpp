#include "MathLibrary\Transform.h"

namespace DersEngine
{
	namespace Maths
	{
		Transform::Transform() : 
			position(Vector3f(0,0,0)), scale(Vector3f(0,0,0)), rotation(Quaternion())
		{

		}

		Transform::Transform(Vector3f position) : 
			position(position), scale(Vector3f(0, 0, 0)), rotation(Quaternion())
		{

		}

		Transform::Transform(Vector3f position, Vector3f scale) :
			position(position), scale(scale), rotation(Quaternion())
		{

		}

		Transform::Transform(Vector3f position, Vector3f scale, Quaternion rotation) :
			position(position), scale(scale), rotation(rotation)
		{

		}
	}
}