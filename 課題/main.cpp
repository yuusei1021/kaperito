/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
// 
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlib���C�u�������g�p����
#include "main.h"
#include "player.h"
#include "Shot.h"
//�ϐ�
//----------------------------------
int gameCounter;



int enemyImage;
int haikeiImage;



//�\���̒�`
struct FILE_DATA {
	int data1;
	int hiscore;
};

//�t�@�C������`
char filename [] = "data.dat";
struct FILE_DATA fileData;

//�v���g�^�C�v�錾
//----------------------------------



// ========= WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �V�X�e���̏�����
	if (SystemInit() == false)
	{
		return -1;
	}








	// --------�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

		GameMain();



		gameCounter++;
		ScreenFlip();		//����ʂ�\��ʂɏu�ԃR�s�[
	}
	






	DxLib_End();			// DX���C�u�����̏I������
	return 0;				//���̃v���O�����̏I��
}

//---------------------------------------------
// �V�X�e���̏�����
bool SystemInit(void)
{
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

	// ------�O���t�B�b�N�̓o�^�@---------

	// ------�ϐ��������@-----------
	gameCounter = 0;

	////�t�@�C���p�f�[�^������
	//fileData.data1 = 1000;
	//fileData.hiscore = 5000;
	PlayerSystemInit();
	ShotSystemInit();
	//�w�i
	haikeiImage = LoadGraph("image/haikei.png");
	//���@
	

	enemyImage = LoadGraph("image/enemy.png");
	return true;

}

//---------------------------------------------
// �v���C������
void GameMain(void)
{
	/*if ((CheckHitKey(KEY_INPUT_UP)))   fileData. hiscore += 100;
	if ((CheckHitKey(KEY_INPUT_DOWN)))   fileData. hiscore -= 100;
	if ((CheckHitKey(KEY_INPUT_LEFT)))   fileData. data1 -= 100;
	if ((CheckHitKey(KEY_INPUT_RIGHT)))   fileData. data1 += 100;

	if ((CheckHitKey(KEY_INPUT_S)))   SaveData();
	if ((CheckHitKey(KEY_INPUT_L)))   LoadData();*/
	PlayerConttrol();
	ShotConttrol();
	GameMainDraw();
	PlayerDraw();
	shotDraw();

}


//---------------------------------------------
// �v���C���̕`��
void GameMainDraw(void)
{
	DrawGraph(0, 0, haikeiImage, true);
	


	DrawGraph(0, 0, enemyImage, true);

	//DrawFormatString(0, 0, 0xFFFFFF, "GameMain : %d", gameCounter);
}
