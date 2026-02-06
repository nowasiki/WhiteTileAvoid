#include "game.h"
#include <graphics.h>
#include <time.h>
#include <stdio.h>

int main() {
	//FreeConsole();
	srand((unsigned int)time(NULL));

	initBlack();

	HWND window = initgraph(WIN_LENGTH, WIN_HEIGHT);
	SetWindowText(window,"别踩白块1.0.0-By诺威施奇Nowasiki");
	setbkcolor(WHITE);
	cleardevice();

	drawAll();

	//char a = getchar();
	while (1) {
		
		bool ret = play();
		if (!ret) {
			char a[128] = { 0 };
			sprintf_s(a, "游戏结束！你获得了%d分！恭喜！",score);
			MessageBox(NULL,a, "a", MB_OK | MB_ICONINFORMATION);
			break;
		}
		drawAll();
	}
	closegraph();
	return 0;
}