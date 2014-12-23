#ifndef ENTITY_H
#define ENTITY_H

#include "base.h"

namespace Whitedrop {
	class Entity {
	public:
		Entity(std::string mesh, std::string id, Ogre::Vector3 dimensions, Ogre::Vector3 position, std::string material);
		Entity(const Entity &ref);
		Entity& operator=(const Entity ent);
		virtual ~Entity(void);

		const std::string type = "STATIC";
		virtual void setup(Ogre::SceneManager* sceneMgr);
		virtual bool update(void);

	protected:
		std::string 			mMesh = "cube.mesh";
		std::string 			mId;
		std::string 			mMaterial;
		Ogre::Vector3 			mDimensions;
		Ogre::Vector3 			mPosition;
		Ogre::Entity* 			mEntity;
		Ogre::SceneNode* 		mNode;

	};
}


#endif