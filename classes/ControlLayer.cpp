#include "ControlLayer.h"
#include "SimpleAudioEngine.h"

ControlLayer::ControlLayer(){

}

ControlLayer::~ControlLayer(){

}

bool ControlLayer::init(){
	if(!Layer::init())
		return false;

	Size winsize = Director::getInstance()->getWinSize();
	Sprite* normalPause = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_resume_nor.png"));
	Sprite* pressPause  = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_resume_pressed.png"));
	pPauseItem = MenuItemSprite::create(normalPause,pressPause,nullptr,CC_CALLBACK_1(ControlLayer::menuPauseCallback,this));
	Point pos = Point(normalPause->getContentSize().width/2 + 10,winsize.height - normalPause->getContentSize().height/2 -10);
	pPauseItem->setPosition(pos);
	Menu * menuPause = Menu::create(pPauseItem,nullptr);
	menuPause->setPosition(Point::ZERO);
	this->addChild(menuPause);

	
	return true;
}

void ControlLayer::menuPauseCallback(cocos2d::Ref* sender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if(!Director::getInstance()->isPaused()){
		Director::getInstance()->pause();
		pPauseItem->setNormalImage(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_pause_pressed.png")));
		pPauseItem->setSelectedImage(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_resume_pressed.png")));
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
	}else{
		Director::getInstance()->resume();
		pPauseItem->setNormalImage(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_resume_nor.png")));
		pPauseItem->setSelectedImage(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_resume_pressed.png")));
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
}