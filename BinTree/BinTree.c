#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

typedef int Elem;

typedef struct BinNode
{
	Elem data;
	struct BinNode *left;
	struct BinNode *right;
}* BinTree;

BinTree initBinTree(Elem x)
{
	BinTree r;
	r = (BinTree)malloc(sizeof(struct BinNode));
	r->data = x;
	r->left = r->right = NULL;
	return r;
}

void preprint(BinTree r)
{
	if (r == NULL)
	{
		return;
	}
	printf("%d ", r->data);
	preprint(r->left);
	preprint(r->right);
}

BinTree findX(BinTree r, Elem x)
{
	if (!r)
	{
		return NULL;
	}
	if (r->data == x)
	{
		return r;
	}
	BinTree found;
	found = findX(r->left, x);
	return found ? found : findX(r->right, x);
}

void printTree(BinTree r, int depth)
{
	int i = 0;
	for (i = 0; i < depth; i++)
	{
		printf(" ");
	}
	if (!r)
	{
		printf("[/]\n");
	}
	else
	{
		printf("%d\n", r->data);
		printTree(r->left, depth + 1);
		printTree(r->right, depth + 1);
	}
}

int insert(BinTree bt, Elem p, int LorR, Elem x)
{
	BinTree found; 
	found = findX(bt, p);
	if (!found)
	{
		return 0;
	}
	if (LorR == 0)
	{
		if (found->left)return;
		found->left = initBinTree(x);
	}
	else
	{
		if (found->right)
		{
			return 0;
		}
		found->right = initBinTree(x);
		return 1;
	}
}

int main()
{
	BinTree bt = initBinTree(11);

	return 0;
}