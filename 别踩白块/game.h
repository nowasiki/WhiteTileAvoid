#pragma once

//一共有4行5列
#define COL 5
#define ROW 4

//绘制窗口500*480
#define WIN_LENGTH 500
#define WIN_HEIGHT 480

//每一个块为100*120
#define LENGTH 100
#define HEIGHT 120

extern int score;      // 声明
extern int map[ROW];   // 声明

void initBlack();
void drawWhiteGrid();
void drawBlackBlocks();
void drawAll();
bool play();