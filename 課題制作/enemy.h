#pragma once
//�G
#define	ENEMY_SIZE_X	32	//�G�摜�̉��T�C�Y
#define	ENEMY_SIZE_Y	32	//�G�摜�̏c�T�C�Y

bool enemySystemInit(void);
void enemyDraw(void);
void enemyControl(void);

extern bool enemyFlag;
extern int enemyPosX;		//�\���p�̍��W���L�����Ă����ϐ�
extern int enemyPosY;		//�\���p�̍��W���L�����Ă����ϐ�
