#include "ShopScene.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include "time.h"
#include"SingleTone.h"
USING_NS_CC;

using namespace CocosDenshion;



Scene* Shop::ShopScene()
{
	auto Scene = Scene::create();
	auto layer = Shop::create();
	Scene->addChild(layer);
	return Scene;
}


// on "init" you need to initialize your instance
bool Shop::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	srand(time(nullptr));
    

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치

	
	
	close = true;
	bisclick = false;
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	MyMoney = UserDefault::getInstance()->getFloatForKey("money");
	DressNum = UserDefault::getInstance()->getFloatForKey("DressNum");
	AccNum = UserDefault::getInstance()->getFloatForKey("AccNum");

	Quit = MenuItemImage::create("Shop/X.png", "Shop/X_P.png", CC_CALLBACK_1(Shop::menuCallback, this));
	auto menu = Menu::create(Quit, NULL);
	Quit->setVisible(false);
	Quit ->setScale(0.9f);
	menu->setPosition(Vec2(1230, 670));
	this->addChild(menu, 3);

	
	item1 = Sprite::create("Shop/buy.png");
	item1->setAnchorPoint(Vec2(0, 0));
	item1->setPosition(Vec2(1360, 100));
	this->addChild(item1, 2);

	item2 = Sprite::create("Shop/buy.png");
	item2->setAnchorPoint(Vec2(0, 0));
	item2->setPosition(Vec2(1770, 100));
	this->addChild(item2, 2);

	BG2 = Sprite::create("Shop/BG_2.png");
	BG2->setAnchorPoint(Vec2(0, 0));
	BG2->setPosition(Vec2(1280, 10));
	this->addChild(BG2, 1);

	item1->runAction(MoveBy::create(1, Vec2(-870, 0)));
	item2->runAction(MoveBy::create(1, Vec2(-870, 0)));
	BG2->runAction(MoveBy::create(1, Vec2(-870, 0)));

	
	All = Sprite::create();
	this->addChild(All, 2);
	All->setVisible(false);
	item3 = Sprite::create("3.png");
	item3->setPosition(Vec2(635, 320));
	
	All->addChild(item3, 2);

	Button = Sprite::create("2.png");
	Button->setPosition(Vec2(640, 130));
	All->addChild(Button, 2);

	

	Money = Label::createWithTTF("Money", "fonts/Marker Felt.ttf", 24);
	Money->setString(StringUtils::format("%d",MyMoney));
	Money->setPosition(Vec2(150, 670));
	Money->setColor(Color3B(0,0,0));
	this->addChild(Money, 1);
	
	

	Rand = Label::createWithTTF("Random", "fonts/Marker Felt.ttf", 24);
	R = rand() % 10;
	//Rand->setString(StringUtils::format("%d", R));
	Rand->setPosition(Vec2(600, 350));
	this->addChild(Rand, 2);

	
 
	BG = Sprite::create("Shop/BG_3.png");
	BG->setAnchorPoint(Vec2(0, 0));
	BG->setPosition(Vec2(0, 0));
	this->addChild(BG, 0);

	auto coin = Sprite::create("Shop/coin.png");
	coin->setPosition(Vec2(50, 670));
	this->addChild(coin, 2);

	
	scheduleUpdate();
	return true;
}

void Shop::menuCallback(cocos2d::Ref * pSender)
{
	if (bisclick != true)
	{
		UserDefault::getInstance()->setFloatForKey("money", MyMoney);
		UserDefault::getInstance()->setFloatForKey("DressNum", DressNum);
		UserDefault::getInstance()->setFloatForKey("AccNum", AccNum);
		Scene *pScene = New::NewScene();
		Director::getInstance()->replaceScene(pScene);
	}
}
void Shop::onExit()
{
	Layer::onExit();
	//DressNum = 0;
	UserDefault::getInstance()->setFloatForKey("money", MyMoney);
	UserDefault::getInstance()->setFloatForKey("DressNum", DressNum);
	UserDefault::getInstance()->setFloatForKey("AccNum", AccNum);
}
void Shop::onEnter()
{
	Layer::onEnter();
	
}

bool Shop::onTouchBegan(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();

	CCLOG("%f %f", point.x, point.y);
	CCLOG("%d", DressNum);
	Sex = 0;

	if (item1 != nullptr||item2!=nullptr||Button!=nullptr)
	{
		if (close == true)
		{
			if (item1->getBoundingBox().containsPoint(touch->getLocation()))
			{
				item1->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop/buy_p.png"));
				bisclick = true;
				Sex = 1;
	}
			if (item2->getBoundingBox().containsPoint(touch->getLocation()))
			{
				item2->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop/buy_p.png"));
				bisclick = true;
				Sex = 2;
			}
		}
			if (Button->getBoundingBox().containsPoint(touch->getLocation())&&All->isVisible()==true)
			{
				CCLOG("3");
				All->setVisible(false);
				close = true;
				bisclick = false;
			}
	}

	
	
	return true;
}

void Shop::onTouchMoved(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();



	
	

}

void Shop::onTouchEnded(Touch* touch, Event*_event)
{
		if (item1->getBoundingBox().containsPoint(touch->getLocation())&& Sex == 1)
		{
			ClickBuy(1);
			JAJAN();

		}
		if (item2->getBoundingBox().containsPoint(touch->getLocation())  && Sex == 2)
		{
			ClickBuy(2);
			JAJAN();
		}
	
	
	item1->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop/buy.png"));
	item2->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop/buy.png"));
	//Sex = 0;
	
}


void Shop::update(float dt)
{
	static float t = 0;
	if (BG2->getPositionX() < 500)
	{
		Quit->setVisible(true);
	}



}

void Shop::ClickBuy(int Clicknum)
{
	if (bisclick == true)
	{
		if (Clicknum == 1 && MyMoney >= 1000)
		{
			CCLOG("1");
			MyMoney -= 1000;
			Money->setString(StringUtils::format("%d", MyMoney));
			R = rand() % 5;
			Rand->setString(StringUtils::format("%d", R));
			point::get()->DressArr[DressNum] = R;
			point::get()->AbleDress[R] = true;
			DressNum++;
		}
		else if (Clicknum == 2 && MyMoney >= 3000)
		{
			MyMoney -= 3000;
			Money->setString(StringUtils::format("%d", MyMoney));
			R = rand() % 5;
			Rand->setString(StringUtils::format("%d", R));
			point::get()->AccArr[AccNum] = R;
			point::get()->AbleAcc[R] = true;
			AccNum++;
		}
	}

}

void Shop::JAJAN()
{
	All->setVisible(true);
	close = false;
	bisclick = true;
	
	//CCLOG("%d", close);
}


