#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "game.h"

USING_NS_CC;  // == using namespace cocos2d

#define TAG_SPRITE_IMAGE 1000
#define TAG_SCROLL  3000

class Chapter :public Layer
{
public:
	static Scene* ChapterScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event);
	virtual void update(float dt);
	Sprite * All;
	Sprite * AAA;
	Sprite * AAA2;
	Sprite * layer;
	Sprite *mini[2];
	Menu *menu2;
	bool bisClick;
	int ClickNum;
	float TouchFt;
	float TouchSe;
	int num;
	int num2;
	bool isstart;
	Sprite * Cloud;
	Sprite * Logo;
	Sprite * Alice;
	Sprite * Army;
	Sprite * Boss;
	bool Cloudmv = true;
	bool Bossmv = true;
	bool isSc;
	Sprite *Kira;
	Sprite *s[4];
	float scale = 0.5f;
	float scale2 = 0.4f;
	float scale3;
	int se;

	bool istouch = false;
	bool istouch2 = false;
	bool is2 = true;
	bool is22 = true;
	int Maxpos;
	MenuItemImage *Chapters[4];
	Menu* menu;
	Sprite * visible;
	EventListenerTouchOneByOne* listener;
	MenuItemImage * Mode[2];
	MenuItemImage *X;
	Menu * ModeMenu;
	void ModeBtnFunc(Ref*pSender);
	bool LocalToWorldPosition(Node* pSender, Point point);
	void StageBtnFunc(Ref* pSender);
	void MiniFunc(Ref*pSender);
	CREATE_FUNC(Chapter);

};