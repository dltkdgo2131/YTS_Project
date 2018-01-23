#include"HelloWorldScene.h"

//void HelloWorld::boss_Animation(int index)
//{
//	BossSp->stopAllActions();
//	switch (index)
//	{
//	case 1:
//		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Boss_wait.plist");
//		Boss = Animation::create();
//		Boss->setDelayPerUnit(0.1f);
//		CCLOG("11");
//		for (int i = 1; i <= 8; i++)
//			Boss->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("wait_%d.png", i)));
//
//		Boss_m = Animate::create(Boss);
//		BossSp->runAction(RepeatForever::create(Boss_m));
//		break;
//	case 2:
//		CCLOG("22");
//		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Boss/At1/Boss_At1.plist");
//		Boss = Animation::create();
//		Boss->setDelayPerUnit(0.125f);
//
//		for (int i = 1; i <= 4; i++)
//			Boss->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Attack_%d.png", i)));
//
//		Boss_m = Animate::create(Boss);
//		BossSp->runAction(RepeatForever::create(Boss_m));
//		break;
//	case 3:
//		CCLOG("33");
//		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Boss/At2/Boss_At2.plist");
//		Boss = Animation::create();
//		Boss->setDelayPerUnit(0.1f);
//	
//		for (int i = 1; i <= 6; i++)
//			Boss->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("At_2_%d.png", i)));
//
//		Boss_m = Animate::create(Boss);
//		BossSp->runAction(RepeatForever::create(Boss_m));
//		break;
//	}
//
//}