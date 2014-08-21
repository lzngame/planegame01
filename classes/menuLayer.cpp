#include "SimpleAudioEngine.h"
#include "menuLayer.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MenuScene::createScene(){
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init(){
	if(!Layer::init())
		return false;
	PreloadResource();
	Layout();

	auto loadgif = createLoadgif();
	addChild(loadgif);
	loadgif->setPosition(200,200);
	return true;
}

void MenuScene::close(Ref* sender){
	Director::getInstance()->end();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}


void MenuScene::Layout(){
	Size size = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto closeBtn = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(MenuScene::close,this));
	closeBtn->setPosition(Point(origin.x + size.width - closeBtn->getContentSize().width,closeBtn->getContentSize().height));
	auto menu = Menu::create(closeBtn,nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,1);

	Size winSize = Director::getInstance()->getWinSize();
	auto bgImg = Sprite::create("ui/shoot_background/background.png");
	bgImg->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(bgImg);

	auto copyRight = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shoot_copyright.png"));
	copyRight->setAnchorPoint(Point(0.5,0));
	copyRight->setPosition(Point(winSize.width/2,winSize.height/2));
	this->addChild(copyRight);
}

void MenuScene::PreloadResource(){
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot_background.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot.plist");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/background-music1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/bullet.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy1_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy2_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy3_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/game_over.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/get_bomb.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/get_double_laser.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/use_bomb.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/big_spaceship_flying.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/achievement.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/out_porp.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/button.mp3");

	// ±³¾°ÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_music.mp3",true);


}

Sprite* MenuScene::createLoadgif(){
	auto loadgif = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading1.png"));
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(0.2f);
	for(int i=1;i<5;i++){
		auto st = String::createWithFormat("game_loading%d.png",i)->getCString();
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(st));
	}
	Animate* animate = Animate::create(animation);
	Repeat* repeat = Repeat::create(animate,3);
	CallFunc* reapeatdone = CallFuncN::create(CC_CALLBACK_1(MenuScene::loadingDone,this));
	Sequence* seq = Sequence::create(repeat,reapeatdone,nullptr);
	loadgif->runAction(seq);

	this->setKeypadEnabled(true);
	return loadgif;
}

void MenuScene::loadingDone(Node* node){
	auto nextScene = GameLayer::createScene();
	TransitionCrossFade* trans = TransitionCrossFade::create(1,nextScene);
	Director::getInstance()->replaceScene(trans);
}