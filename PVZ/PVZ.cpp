#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<graphics.h>

#define WIN_WIDHT  900
#define WIN_HEIGHT 600

IMAGE imgBg;

void initgame()
{
	loadimage(&imgBg, "res/bj.png");   //º”‘ÿ±≥æ∞Õº∆¨
	initgraph(WIN_WIDHT, WIN_HEIGHT);

}

void updateWindow()
{
	putimage(0, 0, &imgBg);
}

int main()
{
	initgame();
	updateWindow();
	system("pause");

	return 0;
}