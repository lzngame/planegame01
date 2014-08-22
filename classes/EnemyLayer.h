#pragma once
#include "cocos2d.h"
#include "Enemy.h"
#include "EnemyDefine.h"

USING_NS_CC;

class EnemyLayer : public Layer{
public:
	EnemyLayer();
	~EnemyLayer();
	virtual bool init();
	CREATE_FUNC(EnemyLayer);

	void addEnemy1(float dt);
	void addEnemy2(float dt);
	void addEnemy3(float dt);

	void blowupEnemy(EnemySprite* pEnemySprite);
	void removeEnemy(Node* pNode);
	void setScore(int nScore);
	void getScore();
	void updateScore(int score);

	Vector<EnemySprite*> vecEnemy;
	static int m_score;
	LabelBMFont* scoreItem;
};