#include "cocos2d.h"
#include "EnemyDefine.h"

USING_NS_CC;

class EnemySprite:public Node{
private:
	Sprite* pEnemySprite;
	int nLife;
public:
	EnemySprite();
	~EnemySprite();
	virtual bool init();
	CREATE_FUNC(EnemySprite);
	void SetEnemyByType(EnemyType);
	Sprite* getSprite();
	int getLife();
	void loseLife();
	Rect getBoundingBox();
};