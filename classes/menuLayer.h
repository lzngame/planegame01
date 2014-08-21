#ifndef __MENU_SCENE__
#define __MENU_SCENE__
#include "cocos2d.h"
USING_NS_CC;

class MenuScene :public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void close(Ref* send);
	CREATE_FUNC(MenuScene);
private:
	void loadingDone(Node*);
	void PreloadResource();
	void Layout();
	Sprite* createLoadgif();

};


#endif