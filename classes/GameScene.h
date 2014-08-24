#pragma once
#include "cocos2d.h"

USING_NS_CC;

class PlaneLayer;
class BulletLayer;
class EnemyLayer;
class ControlLayer;

enum EnBackground{
	e_BackgroundA = 1,
	e_BackgroundB = 2,
};

class GameLayer :public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLayer);
	PlaneLayer* returnPlaneLayer();

private:
	void backgourndMove(float dt);
	void gameUpdate(float dt);
	bool bulletCollisionEnemy(Sprite* bullet);
	bool enemyCollisionPlane();
	void CreateMoveBg(int,char*);
	void SetLoopBg();
	
	
public:
	PlaneLayer* planeLayer;
	BulletLayer* bulletLayer;
	EnemyLayer* enemyLayer;
	ControlLayer* controlLayer;

};