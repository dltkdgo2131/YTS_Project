#pragma once
#include "cocos2d.h"
#include "MyBodyParser.h"
#include "stdlib.h"
#include "LabelTypingEffect.h"
#include "SingleTone.h" 
USING_NS_CC;

enum _item { bigger, teemo, fast, slow };
class HelloWorld : public Layer
{
public:
	static Scene* createScene();

	/// etc /////////////////
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	PhysicsBody* SpiderBody;
	PhysicsBody *T_CBody;
	PhysicsBody *StickBody;
	PhysicsBody *CakeBody;
	PhysicsBody *BatBody;
	PhysicsBody *ItemBody;
	PhysicsBody *ClearBody;
	Node* StickNode[10];
	Node* follow_Camera;
	Follow* camera;

	float jumpTime = 0.0f;
	int n_JumpCount = 0;

	/// Rect ////////////////
	Rect c_Rect;
	Rect h_Rect[200];
	Rect ca_Rect;

	/// Score ///////////////
	Sprite *s_Collecting_Cake;
	Sprite *s_Collecting_Coin;

	Label * Collecting_Cake;
	Label * Collecting_Coin;
	float tempCake;
	float i_Collecting_Cake;
	int Max_Collecting_Cake = 700;
	float i_Collecting_Coin;
	float tempCoin;

	/// Vector //////////////
	Vec2 C_location;// 플레이어 좌표
	Vec2 LastPosition;

	/// bool ////////////////
	bool bIsjump = false;
	bool bIsDown = false;
	bool isJump = false;
	bool isSlide = false;
	bool isBigger;
	bool isFast;
	bool isPause;

	bool isCrush;
	bool isCrushCake;
	bool isCrushHurdle;
	bool isCrushItem;
	int beCrush;
	int afCrush;

	///clear //////
	/// 종료시 팝업 ///////////
	Node* _Clear;

	Sprite* _clear;
	Sprite* clear_Background;
	Sprite* black_Background;

	Label* goal;
	Label* clearTerm;
	Label* clearCoin;

	Sprite *back_Clear;
	Sprite *star_tle;
	Sprite *star[3];
	Sprite *Fail_Particle;

	Menu* ClearMenu;
	MenuItemImage *home;
	MenuItemImage *Next;
	MenuItemImage *back;
	void goHome(Object* pSender);
	void goNext(Object* pSender);
	void goBack(Object* pSender);
	int iStar;
	bool isClear;

	///backGround////////////
	void BackGround_Setting();
	void setBackGround();
	int Chapter;
	int Stage;
	Sprite* backGround1; // 배경 반복
	Sprite* backGround2;
	
	Node* chapter2_Background;// 챕터 2
	Node* Bush[2]; 
	Node* Tree[2];
	Sprite* bush[10];
	Sprite* rose[2];
	Sprite* tree[6];
	Sprite* cloud[2];

	Sprite* dungcol[2];
	/// Sprite //////////////

	Sprite* cake[2000];
	Sprite *_Stick1[200];
	Sprite *Hurdle[2000];
	Sprite *Heart[4];
	Sprite *Fiver[5];
	Sprite *Crash[2];

	/// 스토리//

	float time_label;
	int m_label;
	Label *story;
	Vec2 story_Offset;
	Label *NickName;

	/// Script ////////
	Sprite* _script_BackGround1;
	Sprite* _script_BackGround2;
	Sprite* _script_BackGround3;
	Sprite* rabbit;
	Sprite* rabbit2;

	Node * _script;
	Sprite* Alice;
	TTFConfig _config;
	Sprite* script_BackGround;
	Sprite * Skip;
	Sprite * Chat;
	Sprite * Button;
	Sprite * Nick;
	void opacity_Button();
	/// 엘리스 //////////////////
	Sprite* C_1;
	Sprite* _Alice[5];
	PhysicsBody *C_1Body;
	float _AliceDelay;
	int Alice_Condition;
	int sub_Condition;
	int OpacityDirec;
	float A_time;
	float B_time;
	float A_Scale;
	float opacity_time;

	bool isAlice[4];

	void A_opacity();
	void Condition_Process(float dt);
	/// Animation /////////////
	Animation* C_ani_1;
	Animate* C_anim_1;
	Animation* C_ani_2;
	Animate* C_anim_2;
	/// button ////////////////
	//void menuCloseCallback(cocos2d::Ref* pSender);
	/*void _jump(Ref* pSender);*/
	//void _slide(Ref* pSender);

	Sprite* jump_Button;
	Sprite* slide_Button;

	MenuItemImage* stop_Button;
	Menu* _stop;
	void CC_StopButton(Object* pSender);
	Sprite* stop_BackGround;
	Sprite* option;
	Sprite* resume;
	Sprite* stop;
	Sprite* rePlay;

	/// Stage ////////
	bool isStart;
	int ing_Messege;
	void Stage1(Label* label);

	/// function ////////////
	
	void Crashing();
	void inGame(float dt);
	virtual bool onTouchBegan(Touch* touch, Event* _event);
	virtual void onTouchMoved(Touch* touch, Event* _event);
	virtual void onTouchEnded(Touch* touch, Event* _event);

	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	virtual bool init();
	void C_animation(int Select);
	void set_Action(int index);
	void Action_Vat(int index, int _case);
	void Crush_Fail();
	void Check_Star();

	bool LocalToWorldPosition(Node* pSender, Point point);
	/// Init //////////////////////
	void setCamera();
	void setKeyListener();
	void setCharacter();
	void setHeart();
	void setUI();
	void setAnimation();
	void setMath();
	void setClear();
	void setScript();
	void setParticle();
	void crushClear();

	/// 발판 , 케이크, 장애물 /////
	ParticleSystemQuad *CakeParticle;
	Label *plusCoin[30];
	int plusArr = 0;

	Animation* Spider_ani;
	Animate* Spider_anim;
	Sprite* temps;
	Sprite* tempHurdle[2];
	Animation* Bat_ani;
	Animate* Bat_anim;

	Vec2 CakeLocation[2000];

	int direc[2000];
	int bat_Direc[2000];
	bool isCake[2000];
	bool isAddChildCake[2000];
	bool isHurdle[2000];

	int removeCake;
	int removeStick = 0;
	int case_Bat;
	int h_Repeat;
	float Delay_Action[1000];

	int MaxHeart = 4;
	int	NowHeart = 3;
	int CountHurdle = 0;
	int CountCake = 0;
	int CakeSection;

	int lastCakeArr = 0;
	int lastCakeInterval = 0;
	int lastCakeTemp = 0;
	int lastStickArr = 0;
	int StickInterval = 0;

	void basicStick(float width);
	void basicStick(float width, float position);
	void basicCake(int Repeat);
	void JumpCake(int index);
	void JumpTwoCake(int index);
	void VatCake();
	void SlideCake();
	void biggerCake();
	void TeemoCake();
	void EatCake();
	void FastCake();
	void ManyCake();
	void FiverCake();
	void CrashHurdle();

	void update(float dt);
	void MoveCake_Stick(float dt);

	int CollectCake = 0;
	int MaxCake = 0;
	/// item //////////
	int CountItem;
	Sprite *item[200];
	bool isItem[200];
	void EatItem();
	void setItem();

	Sprite *Teemo;
	bool isTeemo;
	float TeemoTime;
	void Action_Teemo();

	float speed;
	float FastTime;

	float SlowTime;

	bool isFiver[6];
	int i_Fiver;
	float FiverTime;

	/// Jump ////////////
	float y = 0.0f;
	float gravity = 0.0f;
	int direction = 0;

	float jump_Speed = 20.0f;
	float jump_accell = 1.25f;
	float y_base = 220.0f;

	void DoJump();
	void JumpProcess();
	/// Chapter /////////
	void chapte1_S1();

	CREATE_FUNC(HelloWorld);

private:
	PhysicsWorld *sceneWorld;
	void SetPhysicsWorld(PhysicsWorld *world) { sceneWorld = world; };
	bool onContactBegin(PhysicsContact &contact);
	bool onContactEnded(PhysicsContact &contact);
};