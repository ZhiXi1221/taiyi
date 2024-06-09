//24.6.1
//


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

struct ZhiWu
{
	int type;
	int frameIndex;
};

struct ZhiWu map[3][9];

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
	loadimage(&imgBg, "res/bg.jpg");   //加载背景图片
	loadimage(&imgBar, "res/bar5.png");  //加载植物栏

	memset(imgZhiWu, 0, sizeof(imgZhiWu));
	memset(map, -1, sizeof(map));

	char name[64];
	for (int i = 0; i < ZHI_WU_COUNT; i++)  //加载植物卡
	{
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i);
		loadimage(&imgCards[i], name);

		int j = 0;
		for (j = 0; j < 20; j++)  //加载植物动画
		{
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", i, j);

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
	curZhiWu = -1;

	initgraph(WIN_WIDHT, WIN_HEIGHT);

}

void updateWindow()
{
	BeginBatchDraw();

	putimage(0, 0, &imgBg);  //打印背景
	putimagePNG(250, 0, &imgBar);  //打印植物栏

	int i = 0;
	for (i = 0; i < ZHI_WU_COUNT; i++)  //打印植物卡
	{
		int x = 338 + i * 65;
		int y = 6;
		putimage(x, y, &imgCards[i]);
	}

	for (i = 0; i < 3; i++)  //打印种植动画
	{
		int j = 0;
		for (j = 0; j < 9; j++)
		{
			if (map[i][j].type > -1)
			{
				int x = 256 + j * 81;
				int y = 179 + i * 102;
				int ZhiWuType = map[i][j].type;
				int Index = map[i][j].frameIndex;
				putimagePNG(x, y, imgZhiWu[ZhiWuType][Index]);
			}
		}
	}

	if (curZhiWu > -1)  //打印植物拖动动画
	{
		IMAGE* img = imgZhiWu[curZhiWu][0];
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
		if (msg.message == WM_LBUTTONDOWN)  //选取植物
		{
			if (msg.x > 338 && msg.x < 338 + 65 * ZHI_WU_COUNT && msg.y < 96)
			{
				curZhiWu =  (msg.x - 338) / 65;
				status = 1;
			}
		}
		else if(msg.message == WM_MOUSEMOVE && 1 == status)  //植物拖动
		{
			curX = msg.x;
			curY = msg.y;
		}
		else if(msg.message == WM_LBUTTONUP)  //植物种植
		{
			if (msg.x > 256 && msg.y > 179 && msg.y < 489)
			{
				int col = (msg.x - 256) / 102;
				int row = (msg.y - 179) / 81;
				if (-1 == map[row][col].type)
				{
					map[row][col].type = curZhiWu;
					map[row][col].frameIndex = 0;
				}
			}
			
			curZhiWu = -1;
			status = 0;
		}
	}

}

void updategame()
{
	int i = 0;
	for (i = 0; i < 3; i++)  //打印种植动画
	{
		int j = 0;
		for (j = 0; j < 9; j++)
		{
			if (map[i][j].type > -1)
			{
				map[i][j].frameIndex++;
				int ZhiWuType = map[i][j].type;
				int Index = map[i][j].frameIndex;

				if (imgZhiWu[ZhiWuType][Index] == NULL) map[i][j].frameIndex = 0;
				
			}
		}
	}
}

int main()
{
	initgame();
	int timer = 0;
	bool flag = true;
	while (1)
	{
		useClick();
		timer += getDelay();
		if (timer > 20)
		{
			flag = true;
			timer = 0;
		}
		if (flag)
		{
			flag = false;
			updategame();
			updateWindow();

		}
	}
	
	system("pause");

	return 0;
}