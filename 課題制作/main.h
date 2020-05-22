#pragma once

enum SCN_ID
{
	SCN_ID_TITLE,		//ﾀｲﾄﾙ画面
	SCN_ID_GAME,		//ｹﾞｰﾑ中
	SCN_ID_GAMECLEAR,   //ｹﾞｰﾑクリア
	SCN_ID_GAMEOVER,	//ｹﾞｰﾑｵｰﾊﾞｰ
	SCN_ID_MAX,
};


//画面
#define	SCREEN_SIZE_X	600	//画面の横サイズ
#define	SCREEN_SIZE_Y	500	//画面の縦サイズ

#define SCROLL_SPEED 2
#define BG_SIZE_Y       1000 //背景の縦サイズ

//ｹﾞｰﾑｻｲｽﾞ
#define	GAME_SIZE_X		600	//ゲームエリアの横サイズ
#define	GAME_SIZE_Y		500	//ゲームエリアの縦サイズ





//プロトタイプ宣言
//----------------------------------
bool SystemInit(void);

bool TitleInit(void);

void TitleScene(void);		//ﾀｲﾄﾙ画面

void TitleDraw(void);		//ﾀｲﾄﾙｼｰﾝ画面

bool GameInit(void);

void GameScene(void);

void GameDraw(void);

bool GameClearInit(void);

void GameClearScene(void);

void GameClearDraw(void);

bool GameOverInit(void);

void GameOverScene(void);

void GameOverDraw(void);

void CheckHitObj(void);

//void PlayerDraw(void);



