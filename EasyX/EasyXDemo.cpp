#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>

int main()
{
	initgraph(800, 600);
	circle(0, 0, 300);
	getchar();
	closegraph();

	return 0;
}