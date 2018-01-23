#include "Mini.h"
#include"SSH.h"
#include"ChapterSelect.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include"SingleTone.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

using namespace CocosDenshion;

Scene* Chapter::ChapterScene()
{
	auto Scene = Scene::create();
	auto layer = Chapter::create();
	Scene->addChild(layer);
	return Scene;
}

// on "init" you need to initialize your instance
bool Chapter::init()
{
	//////////////////////////////
	// 1. super init first

	if (!Layer::init())
	{
		return false;
	}
	srand(time(NULL));
	//listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(Chapter::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치

														 //layerX =

														 //auto listener = EventListenerTouchOneByOne::create();
														 //listener->onTouchBegan = CC_CALLBACK_2(Chapter::onTouchBegan, this);
														 //Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


														 //All = Sprite::create();
														 //this->addChild(All, 1);
														 //
														 //스크롤 뷰에 넣을 레이어 


														 /*auto layer = LayerColor::create(ccc4(255, 255, 255, 255));
														 layer->setContentSize(Size(1280 * 4, 720));*/

	num = 0;
	///
	layer = Sprite::create();
	layer->setAnchorPoint(Vec2(0, 0));
	layer->setPosition(Vec2(1280, 0));
	this->addChild(layer, 3);


	Mode[0] = MenuItemImage::create("Title/Mini.png", "Title/Mini_p.png", CC_CALLBACK_1(Chapter::ModeBtnFunc, this));
	Mode[1] = MenuItemImage::create("Title/StoryBt.png", "Title/StoryBt_p.png", CC_CALLBACK_1(Chapter::ModeBtnFunc, this));
	for (int i = 0; i < 2; i++)
	{
		Mode[i]->setPosition(Vec2(670, 120 + (130 * i)));
		Mode[i]->setTag(i);
		//	Mode[i]->setScale(0.9f);
		//Mode[i]->setScaleX(1.5f);
		ModeMenu = Menu::create(Mode[i], NULL);
		ModeMenu->setPosition(Vec2(0, 0));
		this->addChild(ModeMenu, 2);
	}
	X = MenuItemImage::create("Shop/X.png", "Shop/X_P.png", CC_CALLBACK_1(Chapter::ModeBtnFunc, this));
	X->setPosition(Vec2(970, 800));
	X->setTag(3);
	ModeMenu = Menu::create(X, NULL);
	ModeMenu->setPosition(Vec2(0, 0));
	this->addChild(ModeMenu, 3);

	isstart = false;

	auto BigBg = Sprite::create("Title/BG.png");
	BigBg->setAnchorPoint(Vec2(0, 0));
	BigBg->setPosition(Vec2(0, 0));
	this->addChild(BigBg);

	Cloud = Sprite::create("Title/Cloud.png");
	Cloud->setAnchorPoint(Vec2(0, 0));
	Cloud->setPosition(Vec2(0, 513));
	this->addChild(Cloud, 1);

	Kira = Sprite::create("Kira.png");
	Kira->setAnchorPoint(Vec2(0.5, 0.5));
	Kira->setPosition(Vec2(640, 220));
	Kira->setColor(Color3B(255, 255, 0));
	Kira->setScale(0.5f);
	Kira->setVisible(false);
	this->addChild(Kira, 4);

	visible = Sprite::create("visibleBg.png");
	visible->setAnchorPoint(Vec2(0, 0));
	visible->setPosition(Vec2(1280, 40));
	visible->setScaleY(1.2f);
	visible->setOpacity(150);
	visible->setScaleY(0.65f);
	visible->setVisible(false);
	this->addChild(visible, 2);



	for (int i = 0; i < 4; i++)
	{
		s[i] = Sprite::create(StringUtils::format("Stage%d/BG.png", i + 1));
		s[i]->setAnchorPoint(Vec2(0.5, 0.5));
		s[i]->setPosition(Vec2(640 + (640 * i), 220));
		s[i]->setScale(0.4f);
		s[i]->setVisible(false);
		s[i]->setTag(i);
		layer->addChild(s[i], 3);
	}

	///

	//////


	Logo = Sprite::create("Title/Log.png");
	Logo->setAnchorPoint(Vec2(0.5, 0.5));
	Logo->setPosition(Vec2(700, 800));
	this->addChild(Logo, 2);

	Logo->runAction(MoveBy::create(0.7, Vec2(0, -300)));

	Army = Sprite::create("Title/Army.png");
	Army->setAnchorPoint(Vec2(0.5, 0.5));
	Army->setPosition(Vec2(1480, 500));
	this->addChild(Army, 1);

	Army->runAction(MoveTo::create(0.9, Vec2(870, 220)));

	Alice = Sprite::create("Title/Alice.png");
	Alice->setAnchorPoint(Vec2(0.5, 0.5));
	Alice->setPosition(Vec2(1280, 550));
	this->addChild(Alice, 1);

	Alice->runAction(MoveTo::create(0.7, Vec2(400, 362)));

	Boss = Sprite::create("Title/Boss.png");
	Boss->setAnchorPoint(Vec2(0.5, 0.5));
	Boss->setPosition(Vec2(1400, 500));
	this->addChild(Boss, 1);

	Boss->runAction(MoveTo::create(1, Vec2(1150, 600)));


	////
	/*for (int i = 0; i < 4; i++)
	{
	Chapters[i] = MenuItemImage::create("1.png", "1.png", CC_CALLBACK_1(Chapter::StageBtnFunc, this));
	Chapters[i]->setPosition(Vec2(640 + (640 * i), 220));
	Chapters[i]->setTag(i);
	menu = Menu::create(Chapters[i], NULL);
	menu->setPosition(Vec2(0, 0));
	layer->addChild(menu, 0);
	}*/
	for (int i = 0; i < 2; i++)
	{
		mini[i] = Sprite::create(StringUtils::format("Stage%d/BG.png", i + 1));
		mini[i]->setPosition(Vec2(640 + (640 * i), 220));
		mini[i]->setAnchorPoint(Vec2(0.5, 0.5));
		mini[i]->setTag(i);
		mini[i]->setScale(0.4f);
		mini[i]->setVisible(false);

		layer->addChild(mini[i], 3);
	}

	isSc = false;

	//auto Sc = ScrollView::create(Size(1280, 720), layer);
	//Sc->setDirection(ScrollView::Direction::HORIZONTAL);
	//Sc->setBounceable(false);
	//Sc->setTag(TAG_SCROLL);
	//this->addChild(Sc);

	/*AAA = Sprite::create("1.png");
	AAA->setAnchorPoint(Vec2(0.5, 0.5));
	AAA->setPosition(Vec2(1280, 320));
	layer->addChild(AAA, 2);

	AAA2 = Sprite::create("1.png");
	AAA2->setAnchorPoint(Vec2(0.5, 0.5));
	AAA2->setPosition(Vec2(640, 320));
	this->addChild(AAA2, 2);*/

	bisClick = false;
	ClickNum = -1;


	scheduleUpdate();
	return true;
}

void Chapter::ModeBtnFunc(Ref *pSender)
{
	//CCLOG("CLICK MODE");
	for (int i = 0; i < 2; i++)
	{
		if (((MenuItemImage*)pSender)->getTag() == Mode[i]->getTag())
		{
			//2가 스토리
			//1이 미니게임
			if (i + 1 == 1)
			{
				layer->runAction(MoveTo::create(0.4, Vec2(0, 0)));
				visible->runAction(MoveTo::create(0.4, Vec2(0, 0)));
				Maxpos = 640;
				isstart = true;
				for (int i = 0; i < 2; i++)
				{
					mini[i]->setVisible(true);
					Kira->setVisible(true);
					visible->setVisible(true);
				}
				for (int i = 0; i < 2; i++)
				{
					Mode[i]->setPositionY(770);
				}
				X->setPositionY(420);
				Logo->runAction(MoveBy::create(0.7, Vec2(0, 350)));
			}
			if (i + 1 == 2)
			{
				Maxpos = 1920;
				isstart = true;
				layer->runAction(MoveTo::create(0.4, Vec2(0, 0)));
				visible->runAction(MoveTo::create(0.4, Vec2(0, 0)));
				X->setPositionY(420);
				for (int i = 0; i < 4; i++)
				{
					s[i]->setVisible(true);
					Kira->setVisible(true);
					visible->setVisible(true);
				}
				for (int i = 0; i < 2; i++)
				{
					Mode[i]->setPositionY(770);
				}
				Logo->runAction(MoveBy::create(0.7, Vec2(0, 350)));
			}
		}
	}
	if (((MenuItemImage*)pSender)->getTag() == 3)
	{
		X->setPositionY(800);
		//layer->setPosition(Vec2(0, 0));
		num = 0;
		isstart = false;
		layer->runAction(MoveTo::create(0.4, Vec2(1280, 0)));
		visible->runAction(MoveTo::create(0.4, Vec2(1280, 0)));
		//visible->setVisible(false);
		Kira->setVisible(false);
		Logo->runAction(MoveBy::create(0.7, Vec2(0, -350)));
		for (int i = 0; i < 2; i++)
		{
			//visible->setVisible(false);
			mini[i]->setVisible(false);
			//Kira->setVisible(false);
		}
		for (int i = 0; i < 4; i++)
		{
			s[i]->setVisible(false);
		}
		for (int i = 0; i < 2; i++)
		{
			Mode[i]->setPositionY(120 + (130 * i));
		}
	}
}
void Chapter::update(float dt)
{
	static float t1;

	t1 += 20;
	//CCLOG("%f", t1);

	Kira->setColor(Color3B(255, t1, 0));
	if (t1 > 255)
		t1 = 0;
	//layer->setPosition(Vec2())
	//a;
	static float a = 0.003;

	if (scale2>0.45) // 스케일 최대값
		a *= -1;
	if (scale2 < 0.4) //스케일 최소값 
		a *= -1;
	scale2 += a;


	s[num]->setScale(scale2);
	if (num < 2)
	{
		mini[num]->setScale(scale2);
	}
	Kira->setScale(scale2);

	for (int i = 0; i < 4; i++)
	{
		if (i != num)
		{
			if (s[i]->getScale() > 0.4f)
			{
				scale3 = s[i]->getScale();
				scale3 -= 0.005;
				s[i]->setScale(scale3);
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (i != num)
		{
			if (mini[i]->getScale() > 0.4f)
			{
				scale3 = mini[i]->getScale();
				scale3 -= 0.005;
				mini[i]->setScale(scale3);
			}
		}
	}
	//////////

	if (Cloud->getPositionX() >= 30)
		Cloudmv = true;
	else if (Cloud->getPositionX() <= 0)
		Cloudmv = false;
	if (Cloudmv)
		Cloud->runAction(MoveBy::create(1, Vec2(-3, 0)));
	else
		Cloud->runAction(MoveBy::create(1, Vec2(3, 0)));

	if (Boss->getPositionY() >= 500)
		Bossmv = true;
	else if (Boss->getPositionY() <= 480)
		Bossmv = false;
	if (Bossmv)
		Boss->runAction(MoveBy::create(1, Vec2(0, -3)));
	else
		Boss->runAction(MoveBy::create(1, Vec2(0, 3)));

}
//void Chapter::StageBtnFunc(Ref* pSender)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (((MenuItemImage*)pSender)->getTag() == i)
//		{
//			point::get()->ScreenX = -(1280 * Chapters[i]->getTag());
//			Scene *pScene = New::NewScene();
//			Director::getInstance()->replaceScene(pScene);
//		}
//	}
//
//}
void Chapter::MiniFunc(Ref *pSender)
{
	if (((MenuItemImage*)pSender)->getTag() == 0)
	{
		Scene *pScene = Mini::createScene2();
		Director::getInstance()->replaceScene(pScene);
	}
	if (((MenuItemImage*)pSender)->getTag() == 1)
	{
		//Scene *pScene = ssh::createScene();
		//Director::getInstance()->replaceScene(pScene);
		//
	}

}
bool Chapter::onTouchBegan(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();
	CCLOG("%f %f", point.x, point.y);
	TouchFt = point.x;

	for (int i = 0; i < 4; i++)
	{
		if (LocalToWorldPosition(s[i], touch->getLocation()) && s[i]->isVisible() == true)
		{
			istouch = true;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (LocalToWorldPosition(mini[i], touch->getLocation()) && mini[i]->isVisible() == true)
		{
			istouch2 = true;
		}
	}

	return true;
}

void Chapter::onTouchEnded(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();

	TouchSe = point.x;

	for (int i = 0; i < 4; i++)
	{
		if (LocalToWorldPosition(s[i], touch->getLocation()) && istouch == true && is2 == true && num == i)
		{
			point::get()->ScreenX = -(1280 * s[i]->getTag());
			Scene *pScene = New::NewScene();
			Director::getInstance()->replaceScene(pScene);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (LocalToWorldPosition(mini[i], touch->getLocation()) && istouch2 == true && is22 == true && num == i)
		{
			if (i == 0)
			{
				Scene *pScene = Mini::createScene2();
				Director::getInstance()->replaceScene(pScene);
			}
			if (i == 1)
			{
				Scene *pScene = ssh::createScene();
				Director::getInstance()->replaceScene(pScene);

			}
		}
	}
	istouch = false;
	istouch2 = false;
	is2 = true;
	is22 = true;
	if (isstart == true)
	{
		if (TouchFt > TouchSe&&TouchFt - TouchSe > 100 && layer->getPositionX() > -Maxpos)
		{

			if (layer->getNumberOfRunningActions() < 1) {
				num++;
				layer->runAction(MoveTo::create(0.3, Vec2(640 * -num, 0)));
			}
			CCLOG("1");
		}
		else if (TouchSe > TouchFt&&TouchSe - TouchFt > 100 && layer->getPositionX() < 0)
		{
			if (layer->getNumberOfRunningActions() < 1) {
				num--;
				layer->runAction(MoveTo::create(0.3, Vec2(640 * -num, 0)));
			}
			CCLOG("2");
		}
		else
		{
			CCLOG("else mun");
			if (layer->getNumberOfRunningActions() < 1)
			{
				layer->runAction(MoveTo::create(0.5, Vec2(640 * -num, 0)));
			}
		}
	}
}




void Chapter::onTouchMoved(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();

	//if(layer->getPositionX())
	if (isstart == true)
	{
		if (layer->getPositionX() > -3200 && layer->getPositionX() < 640)
		{
			CCLOG("Moved mun");
			if (layer->getNumberOfRunningActions() < 1)
			{
				layer->setPositionX(640 * -num + point.x - TouchFt);
				is2 = false;
			}
		}

		if (layer->getPositionX() > -3200 && layer->getPositionX() < 640)
		{
			CCLOG("Moved mun");
			if (layer->getNumberOfRunningActions() < 1)
			{
				layer->setPositionX(640 * -num + point.x - TouchFt);
				is22 = false;
			}
		}
	}

	//



	//

}




bool Chapter::LocalToWorldPosition(Node* pSender, Point point)
{
	Point o = pSender->getParent()->convertToWorldSpace(pSender->boundingBox().origin);
	Rect rect = CCRectMake(o.x, o.y, pSender->boundingBox().size.width, pSender->boundingBox().size.height);
	return rect.containsPoint(point);
}