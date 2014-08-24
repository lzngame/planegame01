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

	Size winsize = Director::getInstance()->getWinSize();
	auto body = Sprite::create("ui/shoot/hero1.png");
	body->setPosition(Point(winsize.width/2,body->getContentSize().height/2));
	body->setTag(AIRPLANE);
	this->addChild(body);

	setTouchHandle(body);

	schedule(schedule_selector(PlaneLayer::checkBorder));
	return true;
}

void PlaneLayer::setTouchHandle(Node* body){
	auto lis = EventListenerTouchOneByOne::create();
	lis->setSwallowTouches(true);
	lis->onTouchBegan = [](Touch* touch,Event *event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size size = target->getContentSize();
		Rect rect = Rect(0,0,size.width,size.height);
		if(rect.containsPoint(locationInNode)){
			return true;
		}else{
			return false;
		}
	};
	lis->onTouchEnded = [=](Touch* touch,Event* event){
	};
	lis->onTouchMoved = [](Touch* touch,Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition()+ touch->getDelta());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lis,body);

}

void PlaneLayer::checkBorder(float dt){
	Point location = this->getChildByTag(AIRPLANE)->getPosition();
	Size winsize = Director::getInstance()->getWinSize();
	Size planeSize = this->getChildByTag(AIRPLANE)->getContentSize();
	if(location.x < planeSize.width/2){
		location.x = planeSize.width/2;
	}
	if(location.x > winsize.width - planeSize.width/2){
		location.x = winsize.width - planeSize.width/2;
	}
	if(location.y > winsize.height - planeSize.height/2){
		location.y = winsize.height - planeSize.height/2;
	}
	if(location.y < planeSize.height/2){
		location.y = planeSize.height/2;
	}
	this->getChildByTag(AIRPLANE)->setPosition(location);
}