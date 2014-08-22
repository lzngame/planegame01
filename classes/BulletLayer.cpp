#include "BulletLayer.h"

BulletLayer::BulletLayer(){

}

BulletLayer::~BulletLayer(){

}

bool BulletLayer::init(){
	if(!Layer::init())
		return false;

	BeginBulletShoot();
	return true;
}

void BulletLayer::BeginBulletShoot(float dt){
	this->schedule(schedule_selector(BulletLayer::addBullet),0.2f,kRepeatForever,dt);
}

void BulletLayer::StopBulletShoot(){
	this->unschedule(schedule_selector(BulletLayer::addBullet));
}

void BulletLayer::addBullet(float dt){
	auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");
	if(nullptr == bullet)
		return;
	this->addChild(bullet);
	vecBullet.pushBack(bullet);

	Point planePos = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	Point bulletPos = Point(planePos.x +2,planePos.y + PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height/2);
	bullet->setPosition(bulletPos);

	float flyLen = Director::getInstance()->getWinSize().height + bullet->getContentSize().height/2 - bulletPos.y;
	float flyVelocity = 320/1;
	float realFlyDuration = flyLen/flyVelocity;
	auto actionMove = MoveTo::create(realFlyDuration,Point(bulletPos.x,Director::getInstance()->getWinSize().height + bullet->getContentSize().height/2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(BulletLayer::removeBullet,this));
	Sequence* seq = Sequence::create(actionMove,actionDone,nullptr);
	bullet->runAction(seq);
}

void BulletLayer::removeBullet(Node* pNode){
	if(nullptr == pNode)
		return;
	Sprite* bullet = (Sprite*)pNode;
	this->removeChild(bullet,true);
	vecBullet.eraseObject(bullet);
}