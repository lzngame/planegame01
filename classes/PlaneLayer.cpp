#include "PlaneLayer.h"


PlaneLayer::PlaneLayer(){}

PlaneLayer::~PlaneLayer(){}

PlaneLayer* PlaneLayer::sharedPlane = nullptr;

PlaneLayer* PlaneLayer::create(){
	PlaneLayer* p = new PlaneLayer();
	if(p && p->init()){
		p->autorelease();
		sharedPlane = p;
		return p;
	}else{
		CC_SAFE_DELETE(p);
		return nullptr;
	}
}

bool PlaneLayer::init(){
	if(!Layer::init())
		return false;

}