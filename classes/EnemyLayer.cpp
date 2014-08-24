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
		auto st = String::createWithFormat("enemy1_down%i.png",i)->getCString();
		pAn1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(st));
	}
	AnimationCache::getInstance()->addAnimation(pAn1,"Enemy1Blowup");
	this->schedule(schedule_selector(EnemyLayer::addEnemy1),1.0f);

	return true;
}

void EnemyLayer::addEnemy1(float dt){
	EnemySprite *enemy = EnemySprite::create();
	enemy->SetEnemyByType(Enemy1);
	this->addChild(enemy);
	//enemy->setPositionX(100);
	vecEnemy.pushBack(enemy);
	cocos2d::log(String::createWithFormat("posx:%f",enemy->getPositionX())->getCString());
	auto aMove = MoveTo::create(3.0f,Point(enemy->getPositionX(),0-enemy->getSprite()->getContentSize().height/2));
	auto aDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy,this));
	auto seq = Sequence::create(aMove,aDone,nullptr);
	enemy->runAction(seq);
}

void EnemyLayer::removeEnemy(Node * pNode){
	EnemySprite* enemy = (EnemySprite*)pNode;
	if(enemy != nullptr){
		this->removeChild(enemy,true);
		vecEnemy.eraseObject(enemy);
	}
}

void EnemyLayer::blowupEnemy(EnemySprite* enemy){
	Animation* animation = nullptr;
	enemy->getTag();
	//if(Enemy1 == enemy->getTag()){
		animation = AnimationCache::getInstance()->getAnimation("Enemy1Blowup");

	//}
	Animate* pAnimate = Animate::create(animation);
	auto pActionDone = CallFuncN::create(CC_CALLBACK_0(EnemyLayer::removeEnemy,this,enemy));
	auto seq = Sequence::create(pAnimate,pActionDone,nullptr);
	enemy->getSprite()->runAction(seq);

}