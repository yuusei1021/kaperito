#include "DxLib.h"
#include "main.h"
#include "player.h"
#include "Shot.h"


int shotImage;
int shotPosX, shotPosY;
int shotSpeed;
int shotFlag;
void ShotSystemInit(void)
{
	shotImage = LoadGraph("image/Shot.png");
	shotPosX;
	shotPosY = 0;
	shotSpeed = 5;
	shotFlag = false;
}
void ShotConttrol(void)
{
	if (shotFlag == true)
	{
		shotPosY = shotPosY - shotSpeed;
		if (shotPosY < -SHOT_SIZE_Y)
		{
			shotFlag = false;
		}


	}
}
void shotDraw(void)
{
	DrawGraph(shotPosX, shotPosY, shotImage, true);
}




