#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "game.h"
USING_NS_CC;  // == using namespace cocos2d

#define TAG_SPRITE_IMAGE 1000
#define TAG_SCROLL  3000

class Loading :public Layer
{
public:
	static Scene* LoadingScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event);

	Loading();
	void loadingCallBack(Texture2D *texture);
	void update(float dt);

private:
	Sprite *Background;
	Sprite *Back_Loading;
	Sprite *Loading_Bar;

	Label * Testing;
	Label * _labelLoading;
	Label * _labelPercent;
	int _numberOfSprites;
	int _numberOfLoadedSprites;

	CREATE_FUNC(Loading);
};