#ifndef WHITEDROP_H
#define WHITEDROP_H
#include "base.h"
#include "Vector3.h"
#include "World.h"
#include "Entity.h"

namespace Whitedrop {

	class WhitedropEngine : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
	{
		public:
			WhitedropEngine(void);
			virtual ~WhitedropEngine(void);
			virtual void go();
			virtual void addEntity(Entity ent);
			virtual bool setup();
			virtual void setupWorld();
			
		protected:
		virtual bool configure(void);
		virtual void chooseSceneManager(void);
		virtual void createCamera(void);
		virtual void createFrameListener(void);
		virtual void createScene(void); // Override me!
		virtual void destroyScene(void);
		virtual void createViewports(void);
		virtual void setupResources(void);
		virtual void createResourceListener(void);
		virtual void loadResources(void);
			
		// Ogre::FrameListener
		virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
			
		// OIS::KeyListener
		virtual bool keyPressed( const OIS::KeyEvent &arg );
		virtual bool keyReleased( const OIS::KeyEvent &arg );
		// OIS::MouseListener
		virtual bool mouseMoved( const OIS::MouseEvent &arg );
		virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
		virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
			
		// Ogre::WindowEventListener
		//Adjust mouse clipping area
		virtual void windowResized(Ogre::RenderWindow* rw);
		//Unattach OIS before window shutdown (very important under Linux)
		virtual void windowClosed(Ogre::RenderWindow* rw);
			
		Ogre::Root *mRoot;
		Ogre::Camera* mCamera;
		Ogre::SceneManager* mSceneMgr;
		Ogre::RenderWindow* mWindow;
		Ogre::String mResourcesCfg;
		Ogre::String mPluginsCfg;
		Ogre::OverlaySystem *mOverlaySystem;
			
		// OgreBites
		OgreBites::SdkTrayManager* mTrayMgr;
		OgreBites::SdkCameraMan* mCameraMan;       // basic camera controller
		OgreBites::ParamsPanel* mDetailsPanel;     // sample details panel
		bool mCursorWasVisible;                    // was cursor visible before dialog appeared
		bool mShutDown;
			
		//OIS Input devices
		OIS::InputManager* mInputManager;
		OIS::Mouse*    mMouse;
		OIS::Keyboard* mKeyboard;

		World mWorld;
	};
	bool init();
	void run();
	void spawnEntity(std::string mesh, std::string id, Vector3 position, Vector3 dims, std::string material);


}
#endif