#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<graphics.h>

#define WIN_WIDHT  900
#define WIN_HEIGHT 600

IMAGE imgBg;
IMAGE imgBar;
IMAGE imgCards[3];

enum
{
	WAN_DOU,
	XIAN_RI_KUI,
	ZHI_WU_COUNT
};

void initgame()
{
	loadimage(&imgBg, "res/bj.png");   //º”‘ÿ±≥æ∞Õº∆¨
	loadimage(&imgBar, "res/bj.png");

	char name[64];
	for (int i = 0; i < ZHI_WU_COUNT; i++)
	{
		sprintf_s(name, sizeof(name), "res/%d.png", i + 1);
		loadimage(&imgCards[i], name);
	}

	initgraph(WIN_WIDHT, WIN_HEIGHT);

}

void updateWindow()
{
	BeginBatchDraw();

	putimage(0, 0, &imgBg);
	putimage(250, 0, &imgBar);
	int i = 0;
	for (i = 0; i < ZHI_WU_COUNT; i++)
	{
		int x = 338 + i * 65;
		int y = 6;
		putimage(x, y, &imgCards[i]);
	}

	EndBatchDraw();
}

int main()
{
	initgame();
	while (10)
	{
		useClick();
		updateWindow();
	}
	
	system("pause");

	return 0;
}