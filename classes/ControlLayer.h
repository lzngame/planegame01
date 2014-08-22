#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ControlLayer :public Layer{
public:
	ControlLayer();
	~ControlLayer();
	virtual bool init();
	CREATE_FUNC(ControlLayer);
	void menuPauseCallback(cocos2d::Ref* sender);

public:
	MenuItemSprite* pPauseItem;
};