/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
// 
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"
#include "player.h"
#include "Shot.h"
//変数
//----------------------------------
int gameCounter;



int enemyImage;
int haikeiImage;



//構造体定義
struct FILE_DATA {
	int data1;
	int hiscore;
};

//ファイル情報定義
char filename [] = "data.dat";
struct FILE_DATA fileData;

//プロトタイプ宣言
//----------------------------------



// ========= WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// システムの初期化
	if (SystemInit() == false)
	{
		return -1;
	}








	// --------ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

		GameMain();



		gameCounter++;
		ScreenFlip();		//裏画面を表画面に瞬間コピー
	}
	






	DxLib_End();			// DXライブラリの終了処理
	return 0;				//このプログラムの終了
}

//---------------------------------------------
// システムの初期化
bool SystemInit(void)
{
	// ----------システム処理
	SetWindowText("カペリート");
	//システム処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:フルスクリーン
	if (DxLib_Init() == -1)							//DXライブラリ初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//ひとまずバックバッファに描画

	// ------グラフィックの登録　---------

	// ------変数初期化　-----------
	gameCounter = 0;

	////ファイル用データ初期化
	//fileData.data1 = 1000;
	//fileData.hiscore = 5000;
	PlayerSystemInit();
	ShotSystemInit();
	//背景
	haikeiImage = LoadGraph("image/haikei.png");
	//自機
	

	enemyImage = LoadGraph("image/enemy.png");
	return true;

}

//---------------------------------------------
// プレイ中処理
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
// プレイ中の描画
void GameMainDraw(void)
{
	DrawGraph(0, 0, haikeiImage, true);
	


	DrawGraph(0, 0, enemyImage, true);

	//DrawFormatString(0, 0, 0xFFFFFF, "GameMain : %d", gameCounter);
}
