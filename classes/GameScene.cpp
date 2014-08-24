#include "GameScene.h"
#include "cocos2d.h"
#include "PlaneLayer.h"
#include "ControlLayer.h"
#include "BulletLayer.h"
#include "EnemyLayer.h"
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
	this->schedule(schedule_selector(GameLayer::gameUpdate));

	controlLayer = ControlLayer::create();
	this->addChild(controlLayer);

	planeLayer = PlaneLayer::create();
	this->addChild(planeLayer);

	bulletLayer = BulletLayer::create();
	this->addChild(bulletLayer);

	enemyLayer = EnemyLayer::create();
	this->addChild(enemyLayer);
	return true;

}

void GameLayer::gameUpdate(float dt){
	bool bMoveButt = false;
	for(auto &eBullet :bulletLayer->vecBullet){
		Sprite* pBullet = (Sprite*)eBullet;
		bMoveButt = bulletCollisionEnemy(pBullet);
		if(bMoveButt){
			return;
		}
	}
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

bool GameLayer::bulletCollisionEnemy(Sprite* pBullet){
	for(auto &item :enemyLayer->vecEnemy){
		EnemySprite* enemy = (EnemySprite*)item;
		auto r1 = pBullet->boundingBox();
		auto r2 = enemy->boundingBox();
		//auto r2 = enemy->getBoundingBox();

		if(r1.intersectsRect(r2)){
			if(enemy->getLife()==1) {
				enemy->loseLife();
				enemyLayer->blowupEnemy(enemy);
				break;
			}else{
				enemy->loseLife();
			}
			bulletLayer->removeBullet(pBullet);
			return true;
		}
	}
	return false;
}

bool GameLayer::enemyCollisionPlane(){
	Sprite* pPlane = (Sprite*)planeLayer->getChildByTag(AIRPLANE);
	for(auto &item :enemyLayer->vecEnemy){
		EnemySprite* enemy = (EnemySprite*)item;
		if(pPlane->boundingBox().intersectsRect(enemy->getBoundingBox()) && enemy->getLife() > 0){
			//this->bulletLayer->sto
		}
	}
	return false;
}
