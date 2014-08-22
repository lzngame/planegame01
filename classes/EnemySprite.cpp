#include "Enemy.h"
#include "cocos2d.h"

EnemySprite::EnemySprite(){}

EnemySprite::~EnemySprite(){}

void EnemySprite::SetEnemyByType(EnemyType enType){
	switch (enType)
	{
	case Enemy1:
		pEnemySprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1.png"));
		nLife = ENEMY1_MAXLIFE;
		break;
	case Enemy2:
		pEnemySprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2.png"));
		nLife = ENEMY2_MAXLIFE;
		break;
	case Enemy3:
		pEnemySprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png"));
		nLife = ENEMY3_MAXLIFE;
		break;
	case Enemy4:
		pEnemySprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png"));
		nLife = ENEMY3_MAXLIFE;
		break;
	default:
		break;
	}
	this->addChild(pEnemySprite);
	Size winSize = Director::getInstance()->getWinSize();
	Size enemySize = pEnemySprite->getContentSize();
	int minX = enemySize.width/2;
	int maxX = winSize.width - enemySize.width/2;
	int rangeX = maxX - minX;
	int acturalX = (rand() % rangeX) + minX;
	this->setPosition(Point(acturalX,winSize.height + enemySize.height/2));
}

bool EnemySprite::init(){
	if(!Node::init())
		return false;
	return true;
}

int EnemySprite::getLife(){
	return nLife;

}

Sprite* EnemySprite::getSprite(){
	return pEnemySprite;
}

void EnemySprite::loseLife(){
	--nLife;
}

Rect EnemySprite::getBoundingBox(){
	Rect r = pEnemySprite->boundingBox();
	Point pos = this->convertToWorldSpace(r.origin);
	Rect enemyRect(pos.x,pos.y,r.size.width,r.size.height);
	return r;
}
