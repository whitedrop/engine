#ifndef _WORLD_H_
#define _WORLD_H_

#include "base.h"
#include "Entity.h"
namespace Whitedrop {
	class World {
	public:
		World(Ogre::SceneManager* sceneManager);
		World(void);
		virtual ~World(void);

		virtual void addEntity(Entity entity);

		virtual void setup(void);
		virtual bool update(void);
		virtual void setSceneMgr(Ogre::SceneManager* sceneManager);
	protected:
		Ogre::SceneManager* mSceneMgr;
		std::vector<Entity> staticEntities;
		// std::vector<Entity> dynamicEntities; TODO
	};
}


#endif