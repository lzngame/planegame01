#include "GameScene.h"
#include "cocos2d.h"
USING_NS_CC;

Scene* GameLayer::createScene(){
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init(){
	if(!Layer::init())
		return false;
	SetLoopBg();
	return true;

}

void GameLayer::SetLoopBg(){
	char* imgUrl = "ui/shoot_background/background.png";
	CreateMoveBg(e_BackgroundA,imgUrl);
	CreateMoveBg(e_BackgroundB,imgUrl);
	this->schedule(schedule_selector(GameLayer::backgourndMove));
}

void GameLayer::CreateMoveBg(int tag,char* imgUrl){
	auto bg = Sprite::create(imgUrl);
	bg->setTag(tag);
	bg->setAnchorPoint(Point::ZERO);
	bg->setPosition(Point::ZERO);
	this->addChild(bg);
}

void GameLayer::backgourndMove(float dt){
	auto bgA = (Sprite*)this->getChildByTag(e_BackgroundA);
	auto bgB = (Sprite*)this->getChildByTag(e_BackgroundB);
	bgA->setPositionY(bgA->getPositionY() - 2);
	bgB->setPositionY(bgA->getPositionY() + bgA->getContentSize().height);
	if(0 == bgB->getPositionY())
		bgA->setPositionY(0);
}
