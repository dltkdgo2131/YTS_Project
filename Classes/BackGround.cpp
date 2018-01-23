#include"HelloWorldScene.h"
#define HEIGHT -30
#define VISIBLEWIDTH 2560;
void HelloWorld::BackGround_Setting()
{
	float x1 = backGround1->getPositionX();
	float x2 = backGround2->getPositionX();


	if (x2 < 0)
	{
		x1 = x2;
		x2 = x1 + backGround1->getContentSize().width;
	}

	backGround1->setPosition(x1 - 10.0f, 0);
	backGround2->setPosition(x2 - 10.0f, 0);
	switch (point::get()->Chapter)
	{
	case 1:
		break;
	case 2:
	{
		float bushx1 = Bush[0]->getPositionX();
		float bushx2 = Bush[1]->getPositionX();

		float bush1x1 = bush[0]->getPositionX();
		float bush1x2 = bush[4]->getPositionX();

		float bush2x1 = bush[3]->getPositionX();
		float bush2x2 = bush[7]->getPositionX();

		//float treex1 = tree[1]->getPositionX();
		//float treex2 = tree[3]->getPositionX();

		float cloudx1 = cloud[0]->getPositionX();
		float cloudx2 = cloud[1]->getPositionX();
		if (bushx2 < 0)
		{
			bushx1 = bushx2;
			bushx2 = bushx1 + VISIBLEWIDTH;
		}
		if (bush1x2 < 300)
		{
			bush1x1 = bush1x2;
			bush1x2 = bush1x1 + VISIBLEWIDTH;
		}
		if (bush2x2 < 70)
		{
			bush2x1 = bush2x2;
			bush2x2 = bush2x1 + VISIBLEWIDTH;
		}
		if (cloudx2 < 0)
		{
			cloudx1 = cloudx2;
			cloudx2 = cloudx1 + VISIBLEWIDTH;
		}
		//if (treex2 < 0)
		//{
		//	treex1 = treex2;
		//	treex2 = treex1 + 2560;
		//}
		Bush[0]->setPosition(bushx1 - 7.0f, HEIGHT);
		Bush[1]->setPosition(bushx2 - 7.0f, HEIGHT);
		bush[0]->setPosition((bush1x1)-7.0f, HEIGHT);
		bush[4]->setPosition((bush1x2)-7.0f, HEIGHT);

		bush[3]->setPosition((bush2x1)-10.0f, HEIGHT);
		bush[7]->setPosition((bush2x2)-10.0f, HEIGHT);

		cloud[0]->setPosition(cloudx1 - 3.0f, 620);
		cloud[1]->setPosition(cloudx2 - 3.0f, 620);

		//tree[0]->setPosition(treex1 - 5.0f, HEIGHT);
		//tree[1]->setPosition(treex2 - 5.0f, HEIGHT);
	}
		break;
	case 3:
	{
		float bushx1 = Bush[0]->getPositionX();
		float bushx2 = Bush[1]->getPositionX();

		float treex1 = Tree[0]->getPositionX();
		float treex2 = Tree[1]->getPositionX();

		float dungx1 = dungcol[0]->getPositionX();
		float dungx2 = dungcol[1]->getPositionX();
		if (bushx2 < 0)
		{
			bushx1 = bushx2;
			bushx2 = bushx1 + VISIBLEWIDTH;
		}
		if (treex2 < 0)
		{
			treex1 = treex2;
			treex2 = treex1 + VISIBLEWIDTH;
		}
		if (tree)
			Bush[0]->setPosition(bushx1 - 10.0f, 0);
		Bush[1]->setPosition(bushx2 - 10.0f, 0);

		Tree[0]->setPosition(treex1 - 6.0f, 0);
		Tree[1]->setPosition(treex2 - 6.0f, 0);

		dungcol[0]->setPosition(dungx1 - 3.0f, 0);
		dungcol[1]->setPosition(dungx2 - 3.0f, 0);
		break;
	}
	}
}