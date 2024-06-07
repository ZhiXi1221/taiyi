#define _CRT_SECURE_NO_WARNINGS 1
#include"tools.h"

#define WIN_WIDHT  900
#define WIN_HEIGHT 600

enum
{
	WAN_DOU,
	XIAN_RI_KUI,
	ZHI_WU_COUNT
};

IMAGE imgBg;
IMAGE imgBar;
IMAGE imgCards[ZHI_WU_COUNT];
IMAGE* imgZhiWu[ZHI_WU_COUNT][20];

int curX, curY;
int curZhiWu;

bool FileExist(const char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp == NULL)
	{
		return false;
	}
	else
	{
		fclose(fp);
		return true;
	}
}


void initgame()
{
	loadimage(&imgBg, "res/bg.jpg");   //º”‘ÿ±≥æ∞Õº∆¨
	loadimage(&imgBar, "res/bar5.png");

	memset(imgZhiWu, 0, sizeof(imgZhiWu));

	char name[64];
	for (int i = 0; i < ZHI_WU_COUNT; i++)
	{
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(&imgCards[i], name);

		int j = 0;
		for (j = 0; j < 20; j++)
		{
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", j, j + 1);

			if (FileExist(name))
			{
				imgZhiWu[i][j] = new IMAGE;
				loadimage(imgZhiWu[i][j], name);
			}
			else
			{
				break;
			}
		}
	}
	curZhiWu = 0;

	initgraph(WIN_WIDHT, WIN_HEIGHT);

}

void updateWindow()
{
	BeginBatchDraw();

	putimage(0, 0, &imgBg);
	putimagePNG(250, 0, &imgBar);

	int i = 0;
	for (i = 0; i < ZHI_WU_COUNT; i++)
	{
		int x = 338 + i * 65;
		int y = 6;
		putimage(x, y, &imgCards[i]);
	}
	if (curZhiWu)
	{
		IMAGE* img = imgZhiWu[curZhiWu - 1][0];
		putimagePNG(curX - img->getwidth() / 2, curY - img->getheight() / 2, img);
	}

	EndBatchDraw();
}

void useClick()
{
	ExMessage msg;
	static int status = 0;
	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (338 < msg.x < 338 + 65 * ZHI_WU_COUNT && msg.y < 96)
			{
				int index = (msg.x - 338) / 65;
				status = 1;
				curZhiWu = index + 1;
			}
		}
		else if(msg.message == WM_MOUSEMOVE && status == 1)
		{
			curX = msg.x;
			curY = msg.y;
		}
		else if(msg.message == WM_LBUTTONUP)
		{
			 
		}
	}

}

int main()
{
	initgame();
	while (1)
	{
		useClick();
		updateWindow();
	}
	
	system("pause");

	return 0;
}