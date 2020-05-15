/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
//   
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlib���C�u�������g�p����
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
SCN_ID scnID;	//�ްт̏󋵈ڊǗ��p
SCN_ID ScnID_Old;//�ްт̏�ԊǗ��p


//�ϐ�
//----------------------------------
int gameCounter;
int haikeiImage;
int titleImage;
int overImage;

int haikeiPosX;
int haikeiPosY;
int haikeiPosY1;
int haikeiPosY2;


int enemyImage;



//�t�@�C������֐�
//bool SaveData(void);
//bool LoadData(void);

// ========= WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return 0;
	}

	ClsDrawScreen(); // ��ʏ���

	// --------�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		KeyCheck();

		ClsDrawScreen(); // ��ʏ���

		switch (scnID)
		{
		case SCN_ID_TITLE:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // �t�F�[�h�C�����I�������̏���������
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// �t�F�[�h�A�E�g���I�������̏���������
					fadeIn = true;
					scnID = SCN_ID_GAME;
				}
			}
			TitleScene();
			break;
		case SCN_ID_GAME:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // �t�F�[�h�C�����I�������̏���������
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// �t�F�[�h�A�E�g���I�������̏���������
					fadeIn = true;
					scnID = SCN_ID_GAMEOVER;
				}
			}
			GameScene();
			break;
		case SCN_ID_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // �t�F�[�h�C�����I�������̏���������
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// �t�F�[�h�A�E�g���I�������̏���������
					fadeIn = true;
					scnID = SCN_ID_TITLE;
				}
			}
			GameOverScene();
			break;
		default:
			break;
		}

	}

	DxLib_End();			// DX���C�u�����̏I������
	return 0;				//���̃v���O�����̏I��
}

//---------------------------------------------
// �V�X�e���̏�����
bool SystemInit(void)
{
	bool rtnFlag = true;
	// ----------�V�X�e������
	SetWindowText("�J�y���[�g");
	//�V�X�e������
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:�t���X�N���[��
	if (DxLib_Init() == -1)							//DX���C�u��������������
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//�ЂƂ܂��o�b�N�o�b�t�@�ɕ`��

	haikeiPosY1 = 0;		//�w�i�P��Y���W
	haikeiPosY2 = -BG_SIZE_Y;		//�w�i�QY���W
	PlayerSystemInit();
	KeyInit();

	// ------�O���t�B�b�N�̓o�^�@---------
	//���ى��
	if ((titleImage = LoadGraph("image/title.png")) == -1)
	{
		rtnFlag = false;
	}
	//�Q�[���I�[�o�[
	if ((overImage = LoadGraph("image/over.png")) == -1)
	{
		rtnFlag = false;
	}
	//�w�i
	if ((haikeiImage = LoadGraph("image/haikei.png")) == -1)
	{
		rtnFlag = false;
	}
	
	
	
	//�G
	enemyImage = LoadGraph("image/enemy.png");


	// ------�ϐ��������@-----------
	gameCounter = 0;


	//�t�@�C���p�f�[�^������
	///fileData.data1 = 1000;
	//fileData.hiscore = 5000;

	ShotSystemInit();
	EffectInit();			// �G�t�F�N�g�p����������

	return rtnFlag;
}

//���ټ�ݗp������
bool TitleInit(void)
{
	bool rtnFlag = true;	//�Ԃ�l�p�ϐ�

	scnID = SCN_ID_TITLE;

	return rtnFlag;
}

//���ى�ʏ���
void TitleScene(void)
{
	

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//scnID = SCN_ID_GAME;
	}
	TitleDraw();

}

void TitleDraw(void)
{
	ClsDrawScreen();	//��ʏ���

	//����ۺޕ\��
	DrawGraph(0, 0, titleImage, true);
	
	ScreenFlip();	//�o�b�N�o�b�t�@�ƃt�����g�ޯ̧�����ւ���
}

//�ްѼ�ݗp�̏�����
bool GameInit(void)
{
	bool rtnFlag = true;	// �Ԃ�l�p�ϐ�

	scnID = SCN_ID_GAME;

	return rtnFlag;
}

void GameScene(void)
{
	//PlayerDraw();
	GameDraw();
	PlayerConttrol();
	ShotConttrol();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		//scnID = SCN_ID_GAMEOVER;
		fadeOut = true;
	}
	
}

//---------------------------------------------
// �v���C���̕`��
void GameDraw(void)
{
	ClsDrawScreen();	//���ɂȂ��Ă����ޯ̧��ر����B

	
	//�w�i�`��
	//�w�i�̕`��
	DrawGraph(0, haikeiPosY1, haikeiImage, false);
	DrawGraph(0, haikeiPosY2, haikeiImage, false);

	haikeiPosY1 += 2;
	if (haikeiPosY1 >= BG_SIZE_Y)
	{
		haikeiPosY1 = -BG_SIZE_Y;
	}


	haikeiPosY2 += 2;
	if (haikeiPosY2 >= BG_SIZE_Y)
	{
		haikeiPosY2 = -BG_SIZE_Y;
	}
	
	//haikeiPosY += SCROLL_SPEED;

	PlayerDraw();
	shotDraw();
	/*DrawGraph(0, 450, playerImage, true);

	DrawGraph(150, 450, enemyImage, true);*/

	ScreenFlip();		// ����ʂƕ\��ʂ����ւ���
}

//�ްѵ��ް��݂̏�����
bool GameOverInit(void)
{
	int rtnFlag = true;	//�Ԃ�l�ϐ�

	scnID = SCN_ID_GAMEOVER;

	return rtnFlag;
}

void GameOverScene(void)
{
	
	GameOverDraw();

	
	
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		
		fadeOut = true;
		//scnID = SCN_ID_TITLE;
		
	}
	
}

void GameOverDraw(void)
{
	ClsDrawScreen();	//���ɂȂ��Ă����ޯ̧��ر����B

	DrawGraph(0, 0, overImage, true);

	ScreenFlip();
}






