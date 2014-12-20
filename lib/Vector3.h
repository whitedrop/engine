#ifndef _VECTOR3_
#define _VECTOR3_
#include "base.h"

namespace Whitedrop {
	class Vector3 {
	public:
		Vector3(float x, float y, float z);
		virtual ~Vector3(void);
		virtual Ogre::Vector3 getOgreVector();

	protected:
		float mX;
		float mY;
		float mZ;
	};
}

#endif