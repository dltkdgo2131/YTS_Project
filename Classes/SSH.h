#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ssh : public Layer
{
public:
	PhysicsBody* micBody;
	PhysicsBody* CharBody;
	Animation* C_ani_1;
	Animate* C_anim_1;
	int cg;
	float highScore;
	float godtime;
	float timer = 0;
	float ps = 4.0;
	float t;
	float time1;
	float time2;
	static cocos2d::Scene* createScene();
	bool GameOver;
	Label*hsl; //하이스코어라벨
	Label*spl;
	Label*cbl;
	Label*gl;
	Label*el;
	Label*Score;
	bool gt = false;
	bool bisitem;
	bool setlC_1 = false;
	bool setrC_1 = false;
	bool a = false;
	bool isLeft;
	bool isRight;
	bool bismic[10];
	int sex = 0;
	int micnum;
	int b_Direc;
	bool budo;
	Sprite*randitem;
	Sprite*coin;
	int M;
	//Sprite*jam;
	//Sprite*jam1;
	//Sprite*jam2;
	Sprite*ground;
	Sprite*Restartbt;
	Sprite*background;
	Sprite*background1;
	Sprite*background2;
	Sprite*eunha;
	Sprite*btl;
	Sprite*btr;
	Sprite*mic[10];
	ParticleSystemQuad *particle;
	virtual bool init();
	void update(float dt);
	void menuCloseCallback(Ref* pSender);
	virtual bool onTouchBegan(Touch *touch, Event* _event);
	virtual void onTouchMoved(Touch *touch, Event* _event);
	virtual void onTouchEnded(Touch *touch, Event* _event);
	//virtual void onExit();
	void _animation();
	void Restart();

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	CREATE_FUNC(ssh);
private:
	PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(PhysicsWorld *world) { sceneWorld = world; };
	bool onContactBegin(PhysicsContact &contact);
};

#endif