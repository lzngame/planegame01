#pragma once
#include "cocos2d.h"
#include "PlaneLayer.h"

USING_NS_CC;

class BulletLayer :public Layer{
private:
	Vector<Sprite*> vecBullet;
public:
	BulletLayer();
	~BulletLayer();
	virtual bool init();
	CREATE_FUNC(BulletLayer);

	void BeginBulletShoot(float dt = 0.0f);
	void StopBulletShoot();
	void addBullet(float dt);
	void  removeBullet(Node* pNode);
};