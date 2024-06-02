#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX 10

struct SList {
	int data[MAX];
	int length;
};

void init(struct SList* p)
{
	p->length = 0;
}

void printList(const struct SList* p)
{
	for (int i = 0; i < p->length; i++)
	{
		printf("%d,", p->data[i]);
		putchar('\n');
	}
}

int insert(struct SList* p, int k, int x)
{
	if (k<0 || k>p->length || p->length == MAX - 1)
	{
		return 0;
	}

	else
	{
		for (int i = p->length - 1; i >= k; i--)
		{
			p->data[i + 1] = p->data[i];
		}

		p->data[k] = x;
		p->length++;

		return 1;
	}
}

int erase(struct SList* p, int k, int* px)
{
	if (k < 0 | k >= p->length)
	{
		return 0;
	}

	else
	{
		*px = p->data[k];
		for (int i = k + 1; i < p->length; i++)
		{
			p->data[i - 1] = p->data[i];
		}
		p->length--;

		return 1;
	}
}

int main(int argc, const char* argv[])
{
	struct SList a;
	init(&a);
	printList(&a);
	insert(&a, 1, 11);

	int x;
	int y = erase(&a, 11, &x);

	return 0;
}