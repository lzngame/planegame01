#pragma once 
#include "cocos2d.h"
USING_NS_CC;

enum Enum_Plane{
	AIRPLANE = 1,

};

class PlayScene :public Layer{
public:
	PlayScene();
	~PlayScene();

	static PlayScene* create();
	virtual bool init();

	void checkBorder(float dt);
	void blowUp();
	void removePlane();

	static PlayScene* sharedPlayScene;
	bool isAlive;
};