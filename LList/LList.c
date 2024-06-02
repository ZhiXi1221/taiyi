#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;

};

void init(struct Node** phead)
{
	*phead = NULL;
}

int getLength(struct Node* head)
{
	int len = 0; while (head)
	{
		len++;
		head = head->next;
	}
	return len;
}

void printList(struct Node* head)
{
	while (head)
	{
		printf("%d,", head->data);
		head = head->next;
	}
}

struct Node* createNode(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->next = NULL;
	t->data = x; 
	return t;
}

struct Node* findKth(struct Node* head, int k)
{
	int count = 1;
	struct Node* p;
	p = head;
	while (p && count < k)
	{
		p = p->next;
		count++;
		return p;
	}
}

int insert(struct Node** phead, int k, int x)
{
	if (1 == k)
	{
		return 1;
	}

	struct Node* p; 
	int count = 1; 
	p = *phead;
	while (p && count < k - 1)
	{
		p = p->next;
		count++;
	}
	if (p)
	{
		struct Node* t;
		t = createNode(x);
		t->next = p->next;
		p->next = t;
		return 1;
	}
	else
	{
		return 0;
	}
}

int removeNode(struct Node** phead, int k, int* px) 
{
	if (k < 1)
	{
		return 0;
	}
	else if (k == 1)
	{
		if (*phead)
		{
			*px = (*phead)->data;
			*phead = (*phead)->next;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		struct Node* p;
		p = findKth(*phead, k - 1);
	}
}

int main(int argc, const char* argv[])
{
	struct Node* head; 
	init(&head);
	int k = getLength(head);
	printList(head);
	printf("%d\n", k);

	return 0;
}