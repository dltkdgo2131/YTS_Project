 #include "ShopScene.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include "SingleTone.h"
#include "ChapterSelect.h"
#include "HelloWorldScene.h"
USING_NS_CC;

using namespace CocosDenshion;

Scene* New::NewScene()
{
	auto Scene = Scene::create();
	auto layer = New::create();
	Scene->addChild(layer);
	return Scene;

	
}

// on "init" you need to initialize your instance
bool New::init()
{
	//////////////////////////////
	// 1. super init first

	if (!Layer::init())
	{
		return false;
	}
	srand(time(NULL));

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	int Money2;
	
	num =3;
	num2 = 3;
	Screen = 1;
	Money2 = UserDefault::getInstance()->getFloatForKey("money");
	////////////음악
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == false)
	{
		VolumeNum = 0.5f;
		SimpleAudioEngine::getInstance()->playBackgroundMusic("changing_times.mp3");
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(v2);
		SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
	}


	////////
	//// 나가기 버튼
	auto Quit = MenuItemImage::create("BackBt.png", "BackBt2.png", CC_CALLBACK_1( New::menuCallback, this));
	auto menu = Menu::create(Quit, NULL);
	menu->setPosition(Vec2(100, 640));
	this->addChild(menu, 2);
	///
	

	bisClick = false;
	closetClick = false;
	sexClick1 = false;
	sexClick2 = false;
	OptionClick = false;
	StageClick = false;
	StageClick2 = false;
	auto Money = Label::createWithTTF("Money", "fonts/Marker Felt.ttf", 24);
	Money->setString(StringUtils::format("%d",Money2));
	Money->setPosition(Vec2(610, 670));
	Money->setColor(Color3B(255, 0, 0));
	this->addChild(Money, 2);

	Closet = Sprite::create("Closet.png");
	Closet ->setScale(0.7f);
	Closet->setPosition(Vec2(1000, 65));
	this->addChild(Closet, 2);

	Shop = Sprite::create("Shop.png");
	Shop->setScale(0.7f);
	Shop->setPosition(Vec2(1150, 65));
	this->addChild(Shop, 2);

	Playbt = Sprite::create("PlayBt.png");
	Playbt->setPosition(Vec2(500, 200));
	Playbt->setScale(0.5f);
	Playbt->setVisible(false);
	this->addChild(Playbt, 4);

	Coin = Sprite::create("coin.png");
	Coin->setPosition(Vec2(540, 670));
	this->addChild(Coin, 2);

	All = Sprite::create();
	this->addChild(All, 3);

	PopUp = Sprite::create("4.png");
	PopUp->setPosition(Vec2(650, 370));
	All->addChild(PopUp, 2);

	auto Closebt = MenuItemImage::create("Iven/X.png", "Iven/X_P.png", CC_CALLBACK_1(New::MiniFunc, this));
	Closebt->setPosition(Vec2(1227, 650));
	auto menu2 = Menu::create(Closebt, NULL);
	menu2->setPosition(Vec2(0, 0));
	All->addChild(menu2, 5);

	


	CCLOG("num ss%d", point::get()->ilust_num);
	Alice1 = Sprite::create(StringUtils::format("Iven/Rust/%d.png",point::get()->ilust_num));
	Alice1->setPosition(Vec2(280, 350));
	All ->addChild(Alice1, 5);

	Accessory = Sprite::create("Iven/BG_2.png");
	Accessory->setAnchorPoint(Vec2(0, 0));
	Accessory->setPosition(Vec2(0,0));
	All->addChild(Accessory, 2);

	Dress = Sprite::create("Iven/BG_1.png");
	Dress->setAnchorPoint(Vec2(0, 0));
	Dress->setPosition(Vec2(0,0));
	All->addChild(Dress, 2);
	///////////////  챕터1


	AllCp = Sprite::create();
	this->addChild(AllCp, 1);

	BackGround1 = Sprite::create("Stage1/Bg.png");
	BackGround1->setAnchorPoint(Vec2(0, 0));
	BackGround1->setPosition(Vec2(0, 0));
	AllCp->addChild(BackGround1, 0);


	Doors = Sprite::create("Doors.png");
	Doors->setAnchorPoint(Vec2(0.5, 0.5));
	Doors->setPosition(Vec2(650, 250));
	AllCp->addChild(Doors, 1);

	auto abs = Sprite::create("abs.png");
	abs->setAnchorPoint(Vec2(0, 0));
	abs->setPosition(Vec2(0, 0));
	AllCp->addChild(abs, 1);

	for (int i = 0; i < 4; i++)
	{
		Stage[i] = Sprite::create(StringUtils::format("Stage1/stage%d.png",i+1));
		Stage[i]->setAnchorPoint(Vec2(0, 0));
		Stage[i]->setPosition(Vec2(50+(300*i), 240-(25*i)));
		AllCp->addChild(Stage[i], 1);
	}

	
	starone = Sprite::create("star_0.png");
	starone->setPosition(Vec2(200, 250));
	AllCp->addChild(starone, 1);

	startwo = Sprite::create("star_0.png");
	startwo->setPosition(Vec2(510, 230));
	AllCp->addChild(startwo, 1);

	starthree = Sprite::create("star_0.png");
	starthree->setPosition(Vec2(810, 210));
	AllCp->addChild(starthree, 1);

	starfour = Sprite::create("star_0.png");
	starfour->setPosition(Vec2(1115, 190));
	AllCp->addChild(starfour, 1);
	
	//////////////

	//////// 챕터 2
	BackGround2 = Sprite::create("Stage2/BG.png");
	BackGround2->setAnchorPoint(Vec2(0, 0));
	BackGround2->setPosition(Vec2(1280, 0));
	AllCp->addChild(BackGround2, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage2[i] = Sprite::create(StringUtils::format("Stage2/stage%d.png", i + 1));
		Stage2[i]->setAnchorPoint(Vec2(0, 0));
		Stage2[i]->setScale(0.9f);
		Stage2[i]->setPosition(Vec2(1330 + (300 * i), 220+(30*i)));
		AllCp->addChild(Stage2[i], 1);
	}
	

	starone2 = Sprite::create("star_0.png");
	starone2->setPosition(Vec2(195+1280, 190));
	AllCp->addChild(starone2, 1);

	startwo2 = Sprite::create("star_0.png");
	startwo2->setPosition(Vec2(485 + 1280, 230));
	AllCp->addChild(startwo2, 1);

	starthree2 = Sprite::create("star_0.png");
	starthree2->setPosition(Vec2(790 + 1280, 260));
	AllCp->addChild(starthree2, 1);

	starfour2 = Sprite::create("star_0.png");
	starfour2->setPosition(Vec2(1090 + 1280, 290));
	AllCp->addChild(starfour2, 1);
	//////

	////챕터 3
	BackGround3 = Sprite::create("Stage3/BG.png");
	BackGround3->setAnchorPoint(Vec2(0, 0));
	BackGround3->setPosition(Vec2(2560, 0));
	AllCp->addChild(BackGround3, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage3[i] = Sprite::create(StringUtils::format("Stage3/stage%d.png", i + 1));
		Stage3[i]->setAnchorPoint(Vec2(0, 0));
		Stage3[i]->setScale(0.9f);
		Stage3[i]->setPosition(Vec2(2600 + (300 * i), 250 + -(20 * i)));
		AllCp->addChild(Stage3[i], 1);
	}

	starone3 = Sprite::create("star_0.png");
	starone3->setPosition(Vec2(183 + 2560, 230));
	AllCp->addChild(starone3, 1);

	startwo3 = Sprite::create("star_0.png");
	startwo3->setPosition(Vec2(470 + 2560, 200));
	AllCp->addChild(startwo3, 1);

	
	starthree3 = Sprite::create("star_0.png");
	starthree3->setPosition(Vec2(780 + 2560, 190));
	AllCp->addChild(starthree3, 1);

	starfour3 = Sprite::create("star_0.png");
	starfour3->setPosition(Vec2(1080 + 2560, 170));
	AllCp->addChild(starfour3, 1);
	/////

	////챕터4
	BackGround4 = Sprite::create("Bg.png");
	BackGround4->setAnchorPoint(Vec2(0, 0));
	BackGround4->setPosition(Vec2(3840, 0));
	AllCp->addChild(BackGround4, 0);
	///
	OptionAll = Sprite::create();
	this->addChild(OptionAll, 2);

	OptionBt = Sprite::create("Option/option.png");
	OptionBt->setPosition(Vec2(1200, 650));
	this->addChild(OptionBt, 1);
	
	OptionPop = Sprite::create("Option/BG.png");
	OptionPop->setAnchorPoint(Vec2(0.5, 0.5));
	OptionPop->setPosition(Vec2(640, 357));
	OptionAll->addChild(OptionPop, 2);

	OptionBack = Sprite::create("Option/Option_Back.png");
	OptionBack->setPosition(Vec2(1000, 650));
	OptionAll->addChild(OptionBack, 2);

	VolumeUp = Sprite::create("Option/+.png");
	VolumeUp->setScale(0.8f);
	VolumeUp->setPosition(Vec2(830, 450));
	OptionAll->addChild(VolumeUp,2);
	
	VolumeUp2 = Sprite::create("Option/+.png");
	VolumeUp2->setScale(0.8f);
	VolumeUp2->setPosition(Vec2(830, 260));
	OptionAll->addChild(VolumeUp2, 2);

	VolumeDown = Sprite::create("Option/-.png");
	VolumeDown->setScale(0.8f);
	VolumeDown->setPosition(Vec2(540, 260));
	OptionAll->addChild(VolumeDown, 2);

	VolumeDown2 = Sprite::create("Option/-.png");
	VolumeDown2->setScale(0.8f);
	VolumeDown2->setPosition(Vec2(540, 450));
	OptionAll->addChild(VolumeDown2, 2);
	
	for (int i = 0; i < 3; i++)
	{
		Stick[i] = Sprite::create("Option/Stick.png");
		Stick[i]->setPosition(Vec2(600+(42*i), 450));
		OptionAll->addChild(Stick[i], 2);

		Stick2[i] = Sprite::create("Option/Stick.png");
		Stick2[i]->setPosition(Vec2(600 + (42 * i), 260));
		OptionAll->addChild(Stick2[i], 2);
	}
	for (int i = 3; i < 5; i++)
	{
		Stick[i] = Sprite::create("Option/Stick_X.png");
		Stick[i]->setPosition(Vec2(600 + (42 * i), 450));
		OptionAll->addChild(Stick[i], 2);

		Stick2[i] = Sprite::create("Option/Stick_X.png");
		Stick2[i]->setPosition(Vec2(600 + (42 * i), 260));
		OptionAll->addChild(Stick2[i], 2);
	}
	
	for (int i = 0; i < 2; i++)
	{
			Sound[i] = MenuItemImage::create("Option/Sound.png", "Option/Sound_p.png", CC_CALLBACK_1(New::SoundFunc, this));
			Sound[i]->setPosition(Vec2(430, 450 - (190 * i)));
			Sound[i]->setTag(i);
			menu = Menu::create(Sound[i], NULL);
			menu->setPosition(Vec2(0, 0));
			OptionAll->addChild(menu, 2);


			Sound2[i] = MenuItemImage::create("Option/Sound_X.png", "Option/Sound_X_P.png", CC_CALLBACK_1(New::SoundFunc2, this));
			Sound2[i]->setPosition(Vec2(430, 450 - (190 * i)));
			Sound2[i]->setTag(i);
			Sound2[i]->setVisible(false);
			menu2 = Menu::create(Sound2[i], NULL);
			menu2->setPosition(Vec2(0, 0));
			OptionAll->addChild(menu2, 2);
	}
	
	Credit = MenuItemImage::create("Option/Credit.png", "Option/Credit_P.png", CC_CALLBACK_1(New::Credit_Func, this));
	Credit->setPosition(Vec2(630,150));
	menu3 = Menu::create(Credit, NULL);
	menu3->setPosition(Vec2(0, 0));
	OptionAll->addChild(menu3, 2);

	Bg_Label = Sprite::create("Option/BG_Label.png");
	Bg_Label->setPosition(Vec2(630, 350));
	OptionAll->addChild(Bg_Label, 2);

	Eft_Label = Sprite::create("Option/Effect_Label.png");
	Eft_Label->setPosition(Vec2(630, 550));
	OptionAll->addChild(Eft_Label, 2);

	
	OptionAll->setVisible(false);
	//////



	for (int i = 0; i < 2; i++)
	{

		Bt1[i] = Sprite::create("1.png");
		Bt1[i]->setPosition(Vec2(600 + (100 * i), 630));
		Bt1[i]->setScale(0.7f);
		All->addChild(Bt1[i], 1);
	}
	
	DressAll = Sprite::create();
	this->addChild(DressAll, 4);
	
	for (int i = 0; i < 5; i++)
	{
		SelectDress[i] = Sprite::create(StringUtils::format("Iven/Dress/%d_2.png",i));
		if(i<4)
		   SelectDress[i]->setPosition(Vec2(600 + (130 * i), 500 ));
		else
		   SelectDress[i]->setPosition(Vec2(80 + (130 * i), 380));
	
		DressAll->addChild(SelectDress[i], 4);
	}
	AccAll = Sprite::create();
	this->addChild(AccAll, 4);
	for (int i = 0; i < 5; i++)
	{
		SelectAcc[i] = Sprite::create(StringUtils::format("Iven/Acc/%d_2.png", i));
		if (i<4)
			SelectAcc[i]->setPosition(Vec2(600 + (130 * i), 500));
		else
			SelectAcc[i]->setPosition(Vec2(80 + (130 * i), 380));
		
		AccAll->addChild(SelectAcc[i], 4);
	}
	

	StartStage = Sprite::create("StartStage.png");
	StartStage->setAnchorPoint(Vec2(0.5, 0.5));
	StartStage->setPosition(Vec2(500, 300));
	StartStage->setVisible(false);
	this->addChild(StartStage, 3);
	
	X = Sprite::create("X.png");
	X->setScale(0.7f);
	X->setPosition(Vec2(230,450));
	X->setVisible(false);
	this->addChild(X, 3);

	

	All->setVisible(false);
	DressAll->setVisible(false);
	AccAll->setVisible(false);

	RtArrow = Sprite::create("RightArrow.png");
	RtArrow->setPosition(Vec2(750, 70));
	this->addChild(RtArrow, 1);

	LtArrow = Sprite::create("LeftArrow.png");
	LtArrow->setPosition(Vec2(250, 70));
	this->addChild(LtArrow, 1);

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치

	
	AllCp->setPosition(Vec2(point::get()->ScreenX, 0));
	CCLOG("Screen X = %d", point::get()->ScreenX);
	
	visibleBg = Sprite::create("visibleBg.png");
	visibleBg->setAnchorPoint(Vec2(0, 0));
	visibleBg->setPosition(Vec2(0, 0));
	visibleBg->setOpacity(120);
	visibleBg->setVisible(false);
	this->addChild(visibleBg, 2);
	
	
	scheduleUpdate();

	return true;
}

void New::MiniFunc(Ref*pSender)
{

		closetClick = false;
		All->setVisible(false);
		bisClick = false;
		DressAll->setVisible(false);
		AccAll->setVisible(false);
		visibleBg->setVisible(false);
	
}
void New::SoundFunc(Ref *pSender)
{
	for (int i = 0; i < 2; i++)
	{
		if (((MenuItemImage*)pSender)->getTag() == i)
		{
			if (i == 0)
			{
				SimpleAudioEngine::getInstance()->setEffectsVolume(0);
			}
			else
			{
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			}
			Sound2[i]->setVisible(true);
			Sound[i]->setVisible(false);
		}
	}
}

void New::SoundFunc2(Ref *pSender)
{
	for (int i = 0; i < 2; i++)
	{
		if (((MenuItemImage*)pSender)->getTag() == i)
		{
			if (i == 0)
			{
				SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
			}
			else
			{
				SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			}
			Sound2[i]->setVisible(false);
			Sound[i]->setVisible(true);
		}
	}
}
void New::Credit_Func(Ref * pSender)
{
	CCLOG("SHOW CREDIT");
}
void New::menuCallback(cocos2d::Ref * pSender)
{
	if (bisClick != true)
	{
		SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
		Scene *pScene = Chapter::ChapterScene();
		Director::getInstance()->replaceScene(pScene);
	}
}

bool New::onTouchBegan(Touch* touch, Event* _event)
{

	auto point = touch->getLocation();//클릭좌표얻기

	CCLOG("%f %f", point.x, point.y);

	Sex = 0;
	Sex2 = 0;
	if (Closet != nullptr || Shop != nullptr|| OptionBt !=nullptr|| OptionBack!=nullptr||VolumeUp!=nullptr||RtArrow!=nullptr||LtArrow!=nullptr)
	{

		if (Closet->getBoundingBox().containsPoint(touch->getLocation())&&bisClick!=true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet2.png"));
			Closet->setScale(0.9f);
			closetClick = true;
			Sex = 1;
		}
		if (Shop->getBoundingBox().containsPoint(touch->getLocation())&&bisClick!=true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop2.png"));
			Shop->setScale(0.9f);
			Sex = 2;
		}
		
		if (OptionBt->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			OptionClick = true;
			OptionBt ->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/option_push.png"));
		}
		if (OptionBack->getBoundingBox().containsPoint(touch->getLocation()))
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			//OptionBack->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/Option_Back_P.png"));
			OptionAll->setVisible(false);
			bisClick = false;
		}
		if (VolumeUp->getBoundingBox().containsPoint(touch->getLocation())&&OptionAll->isVisible()==true)
		{
			OptionClick = true;
			VolumeUp->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/+_push.png"));
		}
		if (VolumeUp2->getBoundingBox().containsPoint(touch->getLocation()) && OptionAll->isVisible() == true)
		{
			OptionClick = true;
			VolumeUp2->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/+_push.png"));
		}
		if (VolumeDown->getBoundingBox().containsPoint(touch->getLocation()) && OptionAll->isVisible() == true)
		{
			OptionClick = true;
			VolumeDown->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/-_p.png"));
		}
		if (VolumeDown2->getBoundingBox().containsPoint(touch->getLocation()) && OptionAll->isVisible() == true)
		{
			OptionClick = true;
			VolumeDown2->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/-_p.png"));
		}
		if (RtArrow->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow2.png"));
			RtArrow->setScale(1.2f);
			Sex2 = 1;
			
		}
		if (LtArrow->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow2.png"));
			LtArrow->setScale(1.2f);
			Sex2 = 2;
		}

	}
	if (X->getBoundingBox().containsPoint(touch->getLocation())&&bisClick ==true&&StageClick==false)
	{
		bisClick = false;
		StageClick2 = true;
		X->setVisible(false);
		Playbt->setVisible(false);
		//StartStage->setVisible(false);
	}
	if (Playbt->getBoundingBox().containsPoint(touch->getLocation()) && bisClick == true && StageClick == false&&Playbt->isVisible()==true)
	{
		Scene *pScene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(pScene);
	}
	for (int i = 0; i < 2; i++)
	{
		if (Bt1[i] != nullptr&&closetClick == true)
		{
			if (Bt1[0]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				Dress->setZOrder(5);
				Accessory->setZOrder(4);
				DressAll->setVisible(true);
				AccAll->setVisible(false);
				CCLOG("CLICK DRESS");
			}
			if (Bt1[1]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				Dress->setZOrder(4);
				Accessory->setZOrder(5);
				DressAll->setVisible(false);
				AccAll->setVisible(true);
			
			}
		}

	}
	
	for (int i = 0; i < 5; i++)
	{
		if (SelectDress[i] != nullptr&&SelectAcc[i] != nullptr)
		{
			if (SelectDress[i]->getBoundingBox().containsPoint(touch->getLocation())&&point::get()->AbleDress[i]==true && AccAll->isVisible() == false)
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
				sexClick1 = true;
				CCLOG("DRESS : %d", i); 
			}
			if (SelectAcc[i]->getBoundingBox().containsPoint(touch->getLocation())&&point::get()->AbleAcc[i] ==true && DressAll->isVisible() == false)
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
				sexClick2 = true;
				CCLOG("ACC : %d", i);
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (Stage[i] != nullptr&& bisClick != true&&StageClick2==false)
		{
			if (Stage[i]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				CCLOG("SDDS");
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				StartStage->setVisible(true);
				bisClick = true;
				StageClick = true;
				StageNum = i;
			}
		} 
	}
	
	

		return true;
}


void New::onTouchMoved(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();//클릭좌표얻기
	if (sexClick1 == true)
	{
		SelectDress[ClickNum]->setZOrder(6);
		SelectDress[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
	if (sexClick2 == true)
	{
		SelectAcc[ClickNum]->setZOrder(6);
		SelectAcc[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
}

void New::onTouchEnded(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();
	//// 씬전환
	//Scene *pScene = HelloWorld::createScene();
	//Director::getInstance()->replaceScene(pScene);
	////
	for (int i = 0; i < 5; i++)
	{
		if (SelectDress[i]->getBoundingBox().intersectsRect(Alice1->getBoundingBox()) && AccAll->isVisible() == false)
		{
			point::get()->ilust_num = i;
			CCLOG("TOUCHTOUCHmmm%d",i);
			Alice1->setTexture(Director::getInstance()->getTextureCache()->addImage(StringUtils::format("Iven/Rust/%d.png", i)));
		}
	/*	if (LocalToWorldPosition(Alice1, SelectDress[i]))
		{
			CCLOG("SDSDADASODHAUISFHASUIF");
		}*/
	}
	for (int i = 0; i < 5; i++)
	{
		if (SelectAcc[i]->getBoundingBox().intersectsRect(Alice1->getBoundingBox()) && DressAll->isVisible() == false)
		{
			point::get()->ilust_num = i;
			//Alice1->setTexture(Director::getInstance()->getTextureCache()->addImage(StringUtils::format("Iven/Acc/%d.png", i)));
		}
	}
	if (Closet->getBoundingBox().containsPoint(touch->getLocation()) && Sex == 1)
	{
		MenuClick(1);
	}
	if (Shop->getBoundingBox().containsPoint(touch->getLocation()) && Sex == 2&&bisClick!=true)
	{
		MenuClick(2);
	}
	//////
	if (RtArrow->getBoundingBox().containsPoint(touch->getLocation())&& Sex2 ==1)
	{
		ScreenMove(-1);
	}
	if (LtArrow->getBoundingBox().containsPoint(touch->getLocation())&& Sex2 ==2)
	{
		ScreenMove(1);
	}
	///////
	if (sexClick1 == true)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i<4)
				SelectDress[i]->setPosition(Vec2(600 + (130 * i), 500));
			else
				SelectDress[i]->setPosition(Vec2(80 + (130 * i), 380));
		}
		sexClick1 = false;
	}
	if (sexClick2 == true)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i<4)
				SelectAcc[i]->setPosition(Vec2(600 + (130 * i), 500));
			else
				SelectAcc[i]->setPosition(Vec2(80 + (130 * i), 380));
		}
		sexClick2 = false;
	}
	/////////////////////////////
	if (OptionClick == true)
	{
		if (OptionBt->getBoundingBox().containsPoint(touch->getLocation()))
		{
			OptionAll->setVisible(true);
			bisClick = true;

		}
		if (VolumeUp->getBoundingBox().containsPoint(touch->getLocation()) && num < 5)
		{
			CCLOG("%d",num);
			Stick[num]->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/Stick.png"));
			v1 += 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
			num++;
		}
		if (VolumeUp2->getBoundingBox().containsPoint(touch->getLocation()) && num2 < 5)
		{
			Stick2[num2]->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/Stick.png"));
			v2 += 0.1;
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(v2);
			num2++;
		}
		if (VolumeDown2->getBoundingBox().containsPoint(touch->getLocation()) && num > 0)
		{
			num--;
			v1 -= 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
			Stick[num]->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/Stick_X.png"));
		}
		if (VolumeDown->getBoundingBox().containsPoint(touch->getLocation()) && num2 > 0)
		{
			num2--;
			v2 -= 0.1;
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(v2);
			Stick2[num2]->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/Stick_X.png"));
		}
			OptionClick = false;
			VolumeUp->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/+.png"));
			VolumeUp2->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/+.png"));
			VolumeDown->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/-.png"));
			VolumeDown2->setTexture(Director::getInstance()->getTextureCache()->addImage("Option/-.png"));
			OptionBt->setTexture(Director::getInstance()->getTextureCache()->addImage("Option.png"));
	}
	if (StageClick == true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Stage[i]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				//StartStage->setVisible(true);
				point::get()->StageNum = i + 1;
				CCLOG("stage %d", i+1);
			}
		}
			///////StageClick = false;
			StageNum = -1;
	}
	BtEnded();



}
void New::MenuClick(int Clicknum)
{
	
		if (Clicknum == 1) // 옷장 클릭
		{
			Dress->setZOrder(5);
			Accessory->setZOrder(4);
			bisClick = true;
			visibleBg->setVisible(true);
			DressAll->setVisible(true);
			All->setVisible(true);
			DressOn();
		}
		else if (Clicknum == 2) // 상점 클릭 
		{
			//// 씬전환
			
			Scene *pScene = Shop::ShopScene();
			Director::getInstance()->replaceScene(pScene);
			////	

		}
}


void New::DressOn()
{
	for (int i = 0; i < 100; i++)
	{
		if (point::get()->DressArr[i] != NULL&&point::get()->DressArr[i] > 0)
		{
			CCLOG("angang");
			SelectDress[point::get()->DressArr[i]]->setTexture(Director::getInstance()->getTextureCache()->addImage(StringUtils::format("Iven/Dress/%d_1.png", point::get()->DressArr[i])));
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (point::get()->AccArr[i] != NULL&&point::get()->AccArr[i] > 0)
		{
			
			SelectAcc[point::get()->AccArr[i] ]->setTexture(Director::getInstance()->getTextureCache()->addImage(StringUtils::format("Iven/Acc/%d_1.png", point::get()->AccArr[i])));
		}
	}
	
	
}



void New::ScreenMove(int Num)
{
	if (point::get()->ScreenX < 0&&Num==1)
	{
		Screen += Num;
		point::get()->Chapter = Screen;
		point::get()->ScreenX += 1280 * Num;
		AllCp->runAction(MoveBy::create(0.1, Vec2(1280 * Num, 0)));
	}
	else if(point::get()->ScreenX > -3840 && Num == -1)
	{
		Screen += Num;
		point::get()->Chapter = Screen;
		point::get()->ScreenX += 1280 * Num;
		AllCp->runAction(MoveBy::create(0.1, Vec2(1280 * Num, 0)));
	}
}

void New::BtEnded()
{

	Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet.png"));
	Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop.png"));
	RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow.png"));
	LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow.png"));
	Closet->setScale(0.7f);
	Shop->setScale(0.7f);
	RtArrow->setScale(1.0f);
	LtArrow->setScale(1.0f);
}

void New::update(float dt)
{
	static float t1 = 0;
	static float t2 = 0;
	static float t5 = 1;
	static float t6 = 1;
	static float a = 0.0;
	static float b = 1.0;
	t1 += dt;
	t2 += dt;
	t5 += dt;
	t6 += dt;
	///////////////
	
	if (t5 >1)
	{
		if(closetClick ==false)
		StageMove();
		
			t5 = 0;
	}
	//////////////////


	if (t1 > 0.01&&StageClick)
	{
		CCLOG("%f", t1);
		a += 0.05;
		if (a < 1.0)
		{
			StartStage->setScale(a);
		}
		if (a >1.0)
		{
			X->setVisible(true);
			Playbt->setVisible(true);
			StageClick = false;
		}
		t1 = 0;
	}

	if (t2 > 0.01 && StageClick2)
	{
		a -= 0.05;
		StartStage->setScale(a);
		if (a < 0.0)
		{
			StageClick2 = false;
			StageClick = false;
		}
		t2 = 0;

		
	}
	if (t6 >1)
	{
		static int xa = 1;
		static int xb = 1;
		static int ancle = 5;
		static int a = -2;
		xa += xb;
		

		Doors->runAction(RotateBy::create(2, ancle));
		
		ancle *= a;
		if (a == -2)
		{
			a = -1;
		}
		t6 = 0;
	}
}

void New::StageMove()
{
	static int ax = 30;
	
		//if (point::get()->ScreenX == 0)
		{
			//CCLOG("SEX");

			for (int i = 0; i < 4; i++)
			{
				if (i % 2 == 0)
					Stage[i]->runAction(MoveBy::create(1, Vec2(0, ax)));
				else
					Stage[i]->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			}

			starone->runAction(MoveBy::create(1, Vec2(0, ax)));
			startwo->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			starthree->runAction(MoveBy::create(1, Vec2(0, ax)));
			starfour->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			//ax *= -1;
		}
	//	if (point::get()->ScreenX == -1280)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i % 2 == 0)
					Stage2[i]->runAction(MoveBy::create(1, Vec2(0, ax)));
				else
					Stage2[i]->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			}

			starone2->runAction(MoveBy::create(1, Vec2(0, ax)));
			startwo2->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			starthree2->runAction(MoveBy::create(1, Vec2(0, ax)));
			starfour2->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			//ax *= -1;
		}
		//	if (point::get()->ScreenX == -1280)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i % 2 == 0)
					Stage3[i]->runAction(MoveBy::create(1, Vec2(0, ax)));
				else
					Stage3[i]->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			}

			starone3->runAction(MoveBy::create(1, Vec2(0, ax)));
			startwo3->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			starthree3->runAction(MoveBy::create(1, Vec2(0, ax)));
			starfour3->runAction(MoveBy::create(1, Vec2(0, ax*-1)));
			ax *= -1;
		}
		
}

