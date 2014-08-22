#include "EnemyLayer.h"
#include "cocos2d.h"

USING_NS_CC;

EnemyLayer::EnemyLayer(){}

EnemyLayer::~EnemyLayer(){}

bool EnemyLayer::init(){
	if(!Layer::init())
		return false;

	Vector<SpriteFrame*> vecTemp;
	vecTemp.clear();

	Animation* pAn1 = Animation::create();
	pAn1->setDelayPerUnit(0.1f);
	for(int i=1;i<5;i++){
		//pAn1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("enemy1_down%i.png"));
	}
}