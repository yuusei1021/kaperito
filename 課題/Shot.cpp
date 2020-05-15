#include "DxLib.h"
#include "main.h"
#include "player.h"
#include "Shot.h"


int shotImage;
int shotPosX;
int shotPosY;
int shotSpeed;
void ShotSystemInit(void)
{
	shotImage = LoadGraph("image/Shot.png");
	shotPosX = 0;
	shotPosY = 0;
	shotSpeed = 5;
}
void ShotConttrol(void)
{

}
void shotDraw(void)
{
	DrawGraph(shotPosX, shotPosY, shotImage, true);
}




