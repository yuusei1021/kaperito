#pragma once

enum SCN_ID
{
	SCN_ID_TITLE,		//���ى��
	SCN_ID_GAME,		//�ްђ�
	SCN_ID_GAMEOVER,	//�ްѵ��ް
	SCN_ID_MAX,
};


//���
#define	SCREEN_SIZE_X	600	//��ʂ̉��T�C�Y
#define	SCREEN_SIZE_Y	500	//��ʂ̏c�T�C�Y

#define SCROLL_SPEED 2
#define BG_SIZE_Y       1000 //�w�i�̏c�T�C�Y

//�ްѻ���
#define	GAME_SIZE_X		600	//�Q�[���G���A�̉��T�C�Y
#define	GAME_SIZE_Y		500	//�Q�[���G���A�̏c�T�C�Y

//���@
#define	PLAYER_SIZE_X	48	//���@�摜�̉��T�C�Y
#define	PLAYER_SIZE_Y	48	//���@�摜�̏c�T�C�Y

//�G
#define	ENEMY_SIZE_X	32	//�G�摜�̉��T�C�Y
#define	ENEMY_SIZE_Y	32	//�G�摜�̏c�T�C�Y

//�v���g�^�C�v�錾
//----------------------------------
bool SystemInit(void);

bool TitleInit(void);

void TitleScene(void);		//���ى��

void TitleDraw(void);		//���ټ�݉��

bool GameInit(void);

void GameScene(void);

void GameDraw(void);

bool GameOverInit(void);

void GameOverScene(void);

void GameOverDraw(void);


//void PlayerDraw(void);



