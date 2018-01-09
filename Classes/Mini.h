#pragma once

#include "cocos2d.h"
USING_NS_CC;


class Mini : public cocos2d::Layer
{
public:

	int num;

	int num2;

	int v1;

	int v2;

	int sex;

	int Score;

	int Up;

	float t;

	float gay = 0.0;

	bool GameOver;

	void menuCallback(cocos2d::Ref* Psender);

	Label*Fever;

	Label*start;

	Label*HighScore;

	Label*scorelabel;

	Label*label;

	Label*Restartbt;

	Label*sound1label;

	Label*sound2label;
	/// Sprite/////////

	Sprite*gayZBa;

	Sprite*gayZ;

	Sprite*All;

	Sprite*plus1;

	Sprite*plus2;

	Sprite*minus1;

	Sprite*minus2;

	Sprite*sound1;

	Sprite*sound2;

	Sprite*background;

	Sprite*stageone;

	Sprite*stagetwo;

	Sprite*stagethree;

	Sprite*stagefour;

	Sprite*dressroom;

	Sprite*shop;

	Sprite*Infinitemode;

	Sprite*starone;

	Sprite*startwo;

	Sprite*starthree;

	Sprite*starfour;

	Sprite*Right;

	Sprite*Left;

	Sprite* S1;

	Sprite*game;

	Sprite *Stick[5];

	Sprite*Stick2[5];
	/// Menuitme /////////
	Vec2 _mouse;

	Menu* Arrow;

	MenuItemImage*m_Right;

	MenuItemImage*m_Left;

	int Chapter = 1;

	static cocos2d::Scene* createScene2();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);

	virtual void onTouchMoved(Touch* touch, Event*_event);

	virtual void onTouchEnded(Touch* touch, Event*_event);



	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* _event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* _event);

	void menuCloseCallback(cocos2d::Ref* pSender);

	void v_Right(cocos2d::Ref* pSender);

	void v_Left(cocos2d::Ref* pSender);

	void update(float dt);

	void Restart();

	virtual void onExit();

	CREATE_FUNC(Mini);
};









