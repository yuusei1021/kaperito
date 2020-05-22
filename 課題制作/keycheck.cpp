#include "DxLib.h"		//DxLibײ���؂��g�p����
#include "keycheck.h"

// �L�[����p
bool keyOld[KEY_ID_MAX];					// 1�t���[���O�̃L�[���
bool keyNew[KEY_ID_MAX];					// ���݂̃L�[���
bool keyDownTrigger[KEY_ID_MAX];			// �L�[�������̃g���K�[
bool keyUpTrigger[KEY_ID_MAX];			// �L�[�A�b�v���̃g���K�[

// �L�[����z��̏�����
void KeyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}

// �L�[���̎擾
void KeyCheck(void)
{
	// �P�t���[���O�̃L�[�����R�s�[
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}

	//���݂̃L�[�����擾����
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_CLEAR] = CheckHitKey(KEY_INPUT_RCONTROL);
	keyNew[KEY_ID_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_LEFT] = CheckHitKey(KEY_INPUT_LEFT);
	keyNew[KEY_ID_SHOT] = CheckHitKey(KEY_INPUT_LCONTROL);
	
	// �g���K�[�����擾����
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// �g���K�[���̏�����
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;


		// �g���K�[���̎擾
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}

		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}

	}

}