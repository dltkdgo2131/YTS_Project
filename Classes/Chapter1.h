#pragma once
#include"HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;

void HelloWorld::chapte1_S1()
{
	srand(time(NULL));
	int counting = 0;

	//for (int i = 0; i < 1; i++)
	//{
	//	basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick(); basicStick();
	//}//	SlideCake();
	basicStick(1400);
	StickInterval += 1400;
	switch (Chapter)
	{
	case 1:
		i_Collecting_Cake = 0;
		Max_Collecting_Cake = 700;
		switch (Stage)
		{
		case 1:
			
			basicCake(1);
			basicCake(1);
			basicCake(1);
			JumpCake(1);
			JumpCake(2);
			JumpCake(1);
			JumpTwoCake(1);
			JumpTwoCake(2);
			JumpTwoCake(1);
			TeemoCake();
			FiverCake();
			SlideCake();
			SlideCake();
			VatCake();
			VatCake();
			biggerCake();
			JumpTwoCake(2);
			basicCake(1);
			JumpCake(1);
			JumpCake(2);
			SlideCake();
			JumpCake(2);
			JumpCake(1);
			JumpTwoCake(1);
			JumpTwoCake(2);
			JumpTwoCake(1);
			TeemoCake();
			basicCake(1);
			basicCake(1);
			basicCake(1);
			JumpCake(1);
			JumpCake(2);
			JumpCake(1);
			JumpTwoCake(1);
			JumpTwoCake(2);
			JumpTwoCake(1);
			TeemoCake();
			FiverCake();
			SlideCake();
			SlideCake();
			VatCake();
			VatCake();
			biggerCake();
			JumpTwoCake(2);
			basicCake(1);
			JumpCake(1);
			JumpTwoCake(1);
			JumpTwoCake(2);
			JumpTwoCake(1);
			TeemoCake();
			basicCake(1);
			basicCake(1);
			basicCake(1);
			JumpCake(1);
			JumpCake(2);
			JumpCake(1);
			JumpTwoCake(1);
			JumpTwoCake(2);
			CCLOG("LastCake : %d", lastCakeArr);
			//TeemoCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//VatCake();
			//JumpTwoCake();
			//basicCake(1);
			//FastCake();
			////biggerCake();
			//JumpCake();
			//JumpCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			////biggerCake();
			//JumpCake();
			//JumpCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			//VatCake();
			break;
		case 2:
			//TeemoCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			//TeemoCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//VatCake();
			//JumpTwoCake();
			//basicCake(1);
			//FastCake();
			////biggerCake();
			//JumpCake();
			//JumpCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			break;
		case 3:
			//TeemoCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//VatCake();
			//JumpTwoCake();
			//basicCake(1);
			//FastCake();
			////biggerCake();
			//JumpCake();
			//JumpCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			////biggerCake();
			//JumpCake();
			//JumpCake();
			//JumpTwoCake();
			//JumpTwoCake();
			//SlideCake();
			//SlideCake();
			//FiverCake();
			//basicCake(2);
			//JumpCake();
			//biggerCake();
			//VatCake();
			break;

		case 4:
			break;

		}

	case 3:
		break;
	case 4:
		break;
	}

	//for (int i = 0; i < 500; i++)
	//{

	//	static int random;
	//	static int r_Count = 0;
	//	while (true)
	//	{
	//		random = (rand() % 20) + 1;
	//		if (r_Count <= 0)
	//			break;
	//		if (r_Count >= 1)
	//			if (random != 18)
	//				break;
	//	}
	//	if (r_Count >= 1)
	//		r_Count--;
	//	switch (random)
	//	{
	//	case 1:
	//	case 2:
	//	case 3:
	//	case 4:
	//		basicCake(2);
	//		counting += 10;
	//		break;
	//	case 5:
	//	case 6:
	//	case 7:
	//	case 8:
	//		SlideCake();
	//		counting += 8;
	//		break;
	//	case 9:
	//	case 10:
	//	case 11:
	//	case 12:
	//		JumpCake();
	//		counting += 6;
	//		break;
	//	case 13:
	//	case 14:
	//	case 15:
	//	case 16:
	//		JumpTwoCake();
	//		counting += 10;
	//		break;
	//	case 17:
	//		biggerCake();
	//		counting += 30;
	//		r_Count = 3;
	//		break;
	//	case 18:
	//		TeemoCake();
	//		counting += 20;
	//		break;
	//	case 19:
	//		FastCake();
	//		counting += 40;
	//		break;
	//	case 20:
	//		VatCake();
	//		break;
	//	}
	//	if (counting >= 1000)
	//		break;
		//basicstick(); basicstick();
		//basicstick(); basiccake(1); slidecake(); jumpcake(); jumptwocake(); jumptwocake(); jumptwocake();
		//basiccake(1); slidecake(); slidecake(); jumpcake(); jumpcake(); jumpcake(); jumptwocake(); jumptwocake(); jumptwocake();
		//jumptwocake(); jumpcake();
		//jumptwocake();
	//}
	_clear->setPosition(1400 + (60 * lastCakeArr), _clear->getPositionY());
	basicStick(1300);
	//biggerCake(); 
	//	JumpTwoCake(); basicCake(2);
	//	JumpTwoCake(); JumpTwoCake(); JumpTwoCake(); JumpTwoCake(); 
	//biggerCake(); biggerCake(); biggerCake(); biggerCake();
}