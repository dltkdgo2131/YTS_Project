#include"HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;
#define FPS 1 / 60
void HelloWorld::DoJump()
{
	C_animation(2);
	direction = 1;
	isCrush = false;
	gravity = jump_Speed;
	n_JumpCount++;
}
void HelloWorld::JumpProcess()
{
	switch (direction)
	{
	case 0:
		/*	if (y > y_base)
				y = y_base;*/

		if (isCrush == false || y <= y_base - 50)
		{
			if (!isFiver[5] && !isAlice[3] && !isAlice[2])
			{
				y -= gravity;
				gravity += jump_accell;
			}
		}
		else if (isCrush == true)//&& C_1->getBoundingBox().intersectsCircle(Stick)
		{
			n_JumpCount = 0;
			y = y_base;
		}

		if (isJump == true)
		{
			isJump = false;
			if (isSlide == false)
				C_animation(1);
		}
		break;
	case 1:
		isCrush = false;
		y += gravity;
		if (gravity <= 0.0f)
		{
			direction = 2;
		}
		else
		{
			gravity -= jump_accell;
		}
		break;
	case 2:
		y -= gravity;
		//if (y > y_base)
		//	gravity += jump_accell;

		if (isCrush == false && !isFiver[5] && !isAlice[3] && !isAlice[2] || y > y_base)
			gravity += jump_accell;
		else
		{
			gravity = 0;
			direction = 0;
			//y = y_base;
		}
		break;
	}
}
void HelloWorld::Condition_Process(float dt)
{
	if (isAlice[1])
	{
		if (y < y_base)
			y = y_base;
		if (A_time <= 0.0f)
		{
			C_1->setScale(A_Scale);
			C_1->setTag(2);
			B_time -= 0.1f;
			A_Scale -= 0.01f;
			y_base -= 1.5f;
		}
		if (A_Scale <= 0.8f && C_1->getTag() == 1)
		{
			C_1->setScale(A_Scale + 0.01f);
			B_time -= 0.1f;
			A_Scale += 0.01f;
			y_base += 1.5f;
		}
		else if (A_Scale >= 0.8f)
		{
			C_1->setScale(A_Scale + 0.01f);
		}
		else if (A_Scale <= 0.5f)
		{
			if (FastTime >= 0.0f)
				Alice_Condition = 4;
			else
				Alice_Condition = 1;
			isAlice[1] = false;
			y_base = 220.0f;
			sub_Condition = 3;
			isAlice[3] = true;
			B_time = 3;
		}
	}

	if (isAlice[2] || isFiver[5])
	{
		_AliceDelay += dt;
		for (int i = 0; i < 5; i++)
		{
			_Alice[i]->setVisible(true);
			if (_AliceDelay >= 0.1f * (i + 1) && _Alice[i]->getNumberOfRunningActions() == 0)
			{
				_Alice[i]->setOpacity(255);
				_Alice[i]->setPosition(C_1->getPosition());
				_Alice[i]->runAction(Spawn::create(FadeOut::create(0.5f), MoveBy::create(0.5f, Vec2(-300, 0)), NULL));
			}
			_Alice[i]->setRotation(C_1->getRotation());
		}
		
		/*if (_AliceDelay >= 0.2f)
			_Alice[1]->runAction(RepeatForever::create(Spawn::create(FadeOut::create(0.5f), ScaleTo::create(0.5f, 1.0f), MoveBy::create(0.5f, Vec2(-300, 0)), NULL)));
		if (_AliceDelay >= 0.3f)
			_Alice[2]->runAction(RepeatForever::create(Spawn::create(FadeOut::create(0.5f), ScaleTo::create(0.5f, 1.0f), MoveBy::create(0.5f, Vec2(-300, 0)), NULL)));
		if (_AliceDelay >= 0.4f)
			_Alice[3]->runAction(RepeatForever::create(Spawn::create(FadeOut::create(0.5f), ScaleTo::create(0.5f, 1.0f), MoveBy::create(0.5f, Vec2(-300, 0)), NULL)));
		if (_AliceDelay >= 0.5f)
			_Alice[4]->runAction(RepeatForever::create(Spawn::create(FadeOut::create(0.5f), ScaleTo::create(0.5f, 1.0f), MoveBy::create(0.5f, Vec2(-300, 0)), NULL)));*/
	}

	if (isAlice[3])
	{
		if (sub_Condition == 1)
		{
			C_animation(3);
			sub_Condition = 2;
		}
		if (C_1->getNumberOfRunningActions() == 0)
		{
			sub_Condition = 3;
			if (isSlide)
				C_animation(4);
			else if (direction == 0)
				C_animation(1);
			else if (direction == 1 || direction == 2)
				C_animation(2);
		}
		else if (B_time > 0.0f)
			A_opacity();
		else if (B_time <= 0.0f)
		{
			C_1->setOpacity(255);
			Alice_Condition = 1;
			isAlice[3] = false;
			sub_Condition = 1;
		}
	}

	switch (Alice_Condition)
	{
	case 1:
		//C_1->setScale(A_Scale);
		//A_time = 0;
		break;
	case 2:



		//else if (A_time <= 0 && C_1->getScale() > 0.4f)
		//	C_1->setScale(C_1->getScale() - 0.1f);
		//else
		//	Alice_Condition = 1;
		break;
	case 3:

	case 4:
		break;
	default:
		break;
	}
}
void HelloWorld::C_animation(int Select)
{
	if (sub_Condition != 2)
	{
		C_1->stopAllActions();
		switch (Select)
		{
		case 1:
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_1.plist");
			C_ani_1 = Animation::create();
			C_ani_1->setDelayPerUnit(0.05f);

			for (int i = 1; i <= 6; i++)
				C_ani_1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("run-%d.png", i)));

			C_anim_1 = Animate::create(C_ani_1);
			C_1->runAction(RepeatForever::create(C_anim_1));
			break;
		case 2:
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_Jump_1.plist");
			C_ani_1 = Animation::create();
			C_ani_1->setDelayPerUnit(0.08f);

			for (int i = 1; i <= 10; i++)
				C_ani_1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("jump_%d.png", i)));

			C_anim_1 = Animate::create(C_ani_1);
			C_1->runAction(RepeatForever::create(C_anim_1));
			break;
		case 3:
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_Damage_1.plist");
			C_ani_2 = Animation::create();
			C_ani_2->setDelayPerUnit(0.2f);

			for (int i = 1; i <= 3; i++)
				C_ani_2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Damage_%d.png", i)));

			C_anim_2 = Animate::create(C_ani_2);
			C_1->runAction(C_anim_2);
			break;
			//	C_animation(1);
		case 4:
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_Slide_1.plist");
			C_ani_1 = Animation::create();
			C_ani_1->setDelayPerUnit(0.05f);

			for (int i = 1; i <= 3; i++)
				C_ani_1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Slide_%d.png", i)));

			C_anim_1 = Animate::create(C_ani_1);
			C_1->runAction(RepeatForever::create(C_anim_1));
			break;
		}
	}
}
void HelloWorld::A_opacity()
{
	if (OpacityDirec == 0)
	{
		C_1->setOpacity(C_1->getOpacity() - 5.0f);
		CCLOG("%f", C_1->getOpacity());
		if (C_1->getOpacity() <= 70)
			OpacityDirec == 1;
	}
	else if (OpacityDirec == 1)
	{
		C_1->setOpacity(C_1->getOpacity() + 5.0f);
		if (C_1->getOpacity() >= 250)
			OpacityDirec == 0;
	}

}
//void HelloWorld::_jump(Ref* pSender)
//{
//	if (n_JumpCount < 2)
//		DoJump();
//}
//void HelloWorld::_slide(Ref* pSender) 
//{ 
//	isSlide = true;
//}