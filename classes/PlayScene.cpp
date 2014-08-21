#include "PlayScene.h"

PlayScene::PlayScene():isAlive(true){

}

PlayScene::~PlayScene(){

}

PlayScene* PlayScene::sharedPlayScene = nullptr;

PlayScene* PlayScene::create(){
	PlayScene* p = new PlayScene();
	if(p && p->init()){
		p->autorelease();
		sharedPlayScene = p;
	}else{
		CC_SAFE_DELETE(p);
		return nullptr;
	}
}

bool PlayScene::init(){
	if(!Layer::init()){
		return false;
	}
	return true;
}