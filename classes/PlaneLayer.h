#pragma once
#include "cocos2d.h"
USING_NS_CC;

enum Enum_Plane{
	AIRPLANE = 1,
};

class PlaneLayer :public Layer{
public :
	PlaneLayer();
	~PlaneLayer();
	static PlaneLayer* create();
	virtual bool init();

	void checkBorder(float dt);
	void blowUp();
	void removePlane();

public:
	static PlaneLayer* sharedPlane;
	bool isAlive;

};