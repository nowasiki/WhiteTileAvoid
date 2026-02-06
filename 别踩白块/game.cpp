#include <graphics.h>
#include <stdio.h>
#include <random>
#include <time.h>
#include "game.h"

int map[ROW]; //存储每一行黑格的位置
int score = 0;

void initBlack() {
	for (int i = 0; i < ROW; i++) {
		map[i] = rand() % COL;
	}
}

void drawWhiteGrid() {
	setlinecolor(BLACK);      // 网格边框为黑色
	setfillcolor(WHITE);      // 网格内部为白色

	int x = 0, y = 0;
	for (int i = 0; i < ROW; i++) {
		y = i * HEIGHT;
		for (int j = 0; j < COL; j++) {
			x = j * LENGTH;
			fillrectangle(x, y, x + LENGTH, y + HEIGHT);
		}
	}
}

void drawBlackBlocks() {
	setfillcolor(BLACK);      // 黑格内部为黑色
	setlinecolor(WHITE);      // 黑格外边框为白色

	for (int i = 0; i < ROW; i++) {
		// 绘制黑色填充矩形（带白色边框）
		fillrectangle(LENGTH * map[i], HEIGHT * i,
			LENGTH * (map[i] + 1), HEIGHT * (i + 1));
	}
}
void drawAll() {
	cleardevice();           // 清屏
	drawWhiteGrid();         // 先画白色网格
	drawBlackBlocks();       // 再画黑色格子（会覆盖对应位置的白色网格）
}

bool play() {
	// 循环等待直到左键按下，忽略其他事件（如鼠标移动）
	while (1) {  // 无限循环，直到处理完一次左键点击
		MOUSEMSG msg = GetMouseMsg();  // 阻塞等待下一个鼠标事件
		if (msg.uMsg == WM_LBUTTONDOWN) {  // 只处理左键按下
			int MouseX = msg.x / LENGTH;
			int MouseY = msg.y / HEIGHT;
			if (MouseY == ROW - 1 && MouseX == map[ROW - 1]) {
				for (int i = ROW - 1; i > 0; i--) {
					map[i] = map[i - 1];
				}
				map[0] = rand() % COL;
				score += 10;
				return true;  // 正确点击，返回true，继续游戏
			}
			else {
				return false;  // 错误点击，返回false，结束游戏
			}
		}
		// 如果不是左键按下，继续循环等待（忽略移动等）
	}
}