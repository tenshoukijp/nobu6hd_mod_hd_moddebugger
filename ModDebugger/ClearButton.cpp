#include "ClearButton.h"
#include "TextBox.h"
#include "ModDebugger.h"

HWND hClearButton = NULL;

static HFONT hFont = NULL;

HWND CreateClearButton(HWND hWnd, HINSTANCE hInst ) {

	 hClearButton = CreateWindow(
		"BUTTON",								 // �E�B���h�E�N���X��
		"�N���A",								 // �L���v�V����
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // �X�^�C���w��
		ClearButtonPosX, 5,                     // ���W
		50, 20,                                  // �T�C�Y
		hWnd,                                    // �e�E�B���h�E�̃n���h��
		(HMENU)CLEARBUTTON_ID,                   // ���j���[�n���h��
		hInst,                                   // �C���X�^���X�n���h��
		NULL                                     // ���̑��̍쐬�f�[�^
	);

	hFont = SetButtonFont("�l�r ����", 13, 0);
	SendMessage(hClearButton, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
	return hClearButton;
}

void DeleteClearButton() {
	DeleteObject(hFont);
	DestroyWindow(hClearButton);
}


