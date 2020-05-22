#include "DxLib.h"
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
#include "enemy.h"

int playerImage;				//���@�̉摜ID
int playerPosX;					//���@��X���W
int playerPosY;					//���@��Y���W
int playerSpeed;


void PlayerSystemInit(void)
{
	playerImage = LoadGraph("image/player.png");
	playerPosX = 280;//�����ʒu
	playerPosY = 450;//�����ʒu
	playerSpeed = 5;
}
void PlayerControl(void)
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		playerPosX -= playerSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		playerPosX += playerSpeed;
	}


	if (playerPosX <= 25 - PLAYER_SIZE_X / 2)
	{
		playerPosX = 25 - PLAYER_SIZE_X / 2;
	}
	if (playerPosX >= SCREEN_SIZE_X - PLAYER_SIZE_X)
	{
		playerPosX = SCREEN_SIZE_X - PLAYER_SIZE_X;
	}
	//�e�̔��ˏ���
	if (CheckHitKey(KEY_INPUT_LCONTROL))
	{
		if (shotFlag == false)
		{

			shotPosX = playerPosX;
			shotPosY = playerPosY;
			shotFlag = true;
		}
	}

}

void PlayerDraw(void)
{
	DrawGraph(playerPosX, playerPosY, playerImage, true);
}

