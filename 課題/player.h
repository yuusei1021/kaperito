#pragma once
//���@
#define	PLAYER_SIZE_X	48	//���@�摜�̉��T�C�Y
#define	PLAYER_SIZE_Y	48	//���@�摜�̏c�T�C�Y


void PlayerSystemInit(void);
void PlayerConttrol(void);
void PlayerDraw(void);
//�ϐ�
extern int shotPosX;
extern int shotPosY;

extern int shotFlag;