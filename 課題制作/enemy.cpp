#include "DxLib.h"		//Dxlib���C�u�������g�p����
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
#include "enemy.h"

int enemyImage;	//�G�`��p�o�^�p�ϐ�
int enemyPosX;		//�\���p�̍��W���L�����Ă����ϐ�
int enemyPosY;		//�\���p�̍��W���L�����Ă����ϐ�
int enemySpeed;	//�G�̃X�s�[�h�p�ϐ�

bool enemyFlag;

bool enemySystemInit(void)
{
	bool rtnFlag = true;

	//�G
	enemyImage = LoadGraph("image/enemy.png");
	enemyPosX = GetRand(SCREEN_SIZE_X - ENEMY_SIZE_X);//�����ʒu�i�����W�j
	enemyPosY = -ENEMY_SIZE_Y; //�����ʒu�i�c���W
	enemySpeed = 4;		//�ړ����x
	enemyFlag = true;

	return rtnFlag;
}

void enemyDraw(void)
{
	if (enemyFlag == true)
	{
		DrawGraph(enemyPosX, enemyPosY, enemyImage, true);
	}
}

void enemyControl(void)
{
	enemyPosY += enemySpeed;
	if (enemyPosY >= SCREEN_SIZE_Y)
	{
		enemyPosX = GetRand(SCREEN_SIZE_X - ENEMY_SIZE_X);
		enemyPosY = -ENEMY_SIZE_Y;
	}
}