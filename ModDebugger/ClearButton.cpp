#include "ClearButton.h"
#include "TextBox.h"
#include "ModDebugger.h"

HWND hClearButton = NULL;

static HFONT hFont = NULL;

HWND CreateClearButton(HWND hWnd, HINSTANCE hInst ) {

	 hClearButton = CreateWindow(
		"BUTTON",								 // ウィンドウクラス名
		"クリア",								 // キャプション
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // スタイル指定
		ClearButtonPosX, 5,                     // 座標
		50, 20,                                  // サイズ
		hWnd,                                    // 親ウィンドウのハンドル
		(HMENU)CLEARBUTTON_ID,                   // メニューハンドル
		hInst,                                   // インスタンスハンドル
		NULL                                     // その他の作成データ
	);

	hFont = SetButtonFont("ＭＳ 明朝", 13, 0);
	SendMessage(hClearButton, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
	return hClearButton;
}

void DeleteClearButton() {
	DeleteObject(hFont);
	DestroyWindow(hClearButton);
}



