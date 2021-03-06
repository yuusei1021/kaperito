/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
//   
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
#include "enemy.h"
SCN_ID scnID;	//ｹﾞｰﾑの状況移管理用
SCN_ID ScnID_Old;//ｹﾞｰﾑの状態管理用


//変数
//----------------------------------
int gameCounter;
int haikeiImage;
int titleImage;
int overImage;
int clearImage;

int haikeiPosX;
int haikeiPosY;
int haikeiPosY1;
int haikeiPosY2;

//ファイル操作関数
//bool SaveData(void);
//bool LoadData(void);

// ========= WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return 0;
	}

	ClsDrawScreen(); // 画面消去

	// --------ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		KeyCheck();

		ClsDrawScreen(); // 画面消去

		switch (scnID)
		{
		case SCN_ID_TITLE:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					scnID = SCN_ID_GAME;
				}
			}
			TitleScene();
			break;
		case SCN_ID_GAME:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					if (CheckHitKey(KEY_INPUT_SPACE))
					{
						scnID = SCN_ID_GAMEOVER;
					}
					if (enemyFlag = false)
					{
						scnID = SCN_ID_GAMECLEAR;
					}
					
				}
				
			}
			GameScene();
			break;
		case SCN_ID_GAMECLEAR:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					scnID = SCN_ID_TITLE;
				}
			}
			GameClearScene();
			break;
		case SCN_ID_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
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

	DxLib_End();			// DXライブラリの終了処理
	return 0;				//このプログラムの終了
}

//---------------------------------------------
// システムの初期化
bool SystemInit(void)
{
	bool rtnFlag = true;
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

	haikeiPosY1 = 0;		//背景１のY座標
	haikeiPosY2 = -BG_SIZE_Y;		//背景２Y座標
	enemySystemInit();
	PlayerSystemInit();
	ShotSystemInit();
	EffectInit();			// エフェクト用初期化処理
	KeyInit();

	// ------グラフィックの登録　---------
	//ﾀｲﾄﾙ画面
	if ((titleImage = LoadGraph("image/title.png")) == -1)
	{
		rtnFlag = false;
	}
	//ゲームクリア
	if ((clearImage = LoadGraph("image/clear.png")) == -1)
	{
		rtnFlag = false;
	}
	//ゲームオーバー
	if ((overImage = LoadGraph("image/over.png")) == -1)
	{
		rtnFlag = false;
	}
	//背景
	if ((haikeiImage = LoadGraph("image/haikei.png")) == -1)
	{
		rtnFlag = false;
	}



	


	// ------変数初期化　-----------
	gameCounter = 0;


	//ファイル用データ初期化
	///fileData.data1 = 1000;
	//fileData.hiscore = 5000;

	

	return rtnFlag;
}

//ﾀｲﾄﾙｼｰﾝ用初期化
bool TitleInit(void)
{
	bool rtnFlag = true;	//返り値用変数

	scnID = SCN_ID_TITLE;

	return rtnFlag;
}

//ﾀｲﾄﾙ画面処理
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
	ClsDrawScreen();	//画面消去

	//ﾀｲﾄﾙﾛｺﾞ表示
	DrawGraph(0, 0, titleImage, true);

	ScreenFlip();	//バックバッファとフロントﾊﾞｯﾌｧを入れ替える
}

//ｹﾞｰﾑｼｰﾝ用の初期化
bool GameInit(void)
{
	bool rtnFlag = true;	// 返り値用変数

	scnID = SCN_ID_GAME;

	return rtnFlag;
}

void GameScene(void)
{
	//PlayerDraw();
	GameDraw();
	PlayerControl();
	enemyControl();
	ShotConttrol();
	CheckHitObj();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		//scnID = SCN_ID_GAMEOVER;
		fadeOut = true;
	}
	
}

//---------------------------------------------
// プレイ中の描画
void GameDraw(void)
{
	ClsDrawScreen();	//裏になっているﾊﾞｯﾌｧをｸﾘｱする。


	//背景描画
	//背景の描画
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
	enemyDraw();
	ShotDraw();
	/*DrawGraph(0, 450, playerImage, true);

	DrawGraph(150, 450, enemyImage, true);*/

	ScreenFlip();		// 裏画面と表画面を入れ替える
}


bool GameClearInit(void)
{
	int rtnFlag = true;	//返り値変数

	scnID = SCN_ID_GAMECLEAR;

	return rtnFlag;
}

void GameClearScene(void)
{
	GameClearDraw();



	if (keyDownTrigger[KEY_ID_SPACE])
	{

		fadeOut = true;
		//scnID = SCN_ID_TITLE;

	}
}

void GameClearDraw(void)
{
	ClsDrawScreen();	//裏になっているﾊﾞｯﾌｧをｸﾘｱする。

	DrawGraph(0, 0, clearImage, true);

	ScreenFlip();
}

//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝの初期化
bool GameOverInit(void)
{
	int rtnFlag = true;	//返り値変数

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
	ClsDrawScreen();	//裏になっているﾊﾞｯﾌｧをｸﾘｱする。

	DrawGraph(0, 0, overImage, true);

	ScreenFlip();
}

void CheckHitObj(void)
{
	if ((enemyPosX < shotPosX + SHOT_SIZE_X)
		&& (enemyPosX + ENEMY_SIZE_X > shotPosX)
		&& (enemyPosY < shotPosY + SHOT_SIZE_Y)
		&& (enemyPosY + ENEMY_SIZE_Y > shotPosY))
	{
		enemyFlag = false;				//敵を死亡状態にする
		shotFlag = false;							//弾を非発射状態にする
	}
}