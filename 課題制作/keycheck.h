#pragma once
enum KEY_ID
{
	KEY_ID_SPACE,
	KEY_ID_CLEAR,
	KEY_ID_RIGHT,
	KEY_ID_LEFT,
	KEY_ID_SHOT,
	KEY_ID_MAX,
};

// �v���g�^�C�v�錾
//---------------------
void KeyInit(void);				// �L�[����z��̏���������
void KeyCheck(void);			// �L�[���̎擾


// �L�[����p
extern bool keyOld[KEY_ID_MAX];					// 1�t���[���O�̃L�[���
extern bool keyNew[KEY_ID_MAX];					// ���݂̃L�[���
extern bool keyDownTrigger[KEY_ID_MAX];			// �L�[�������̃g���K�[
extern bool keyUpTrigger[KEY_ID_MAX];			// �L�[�A�b�v���̃g���K�[