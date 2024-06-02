#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int* data;
	int capacity;
	int front;
	int rear;
};

void init(struct Queue* pq, int capacity)
{
	pq->capacity = capacity;
	pq->data = (int*)malloc(sizeof(int) * (capacity + 1));
	pq->front = pq->rear = 0;
}


int isFull(const struct Queue* pq)
{
	if ((pq->rear + 1) % (pq->capacity + 1) == pq->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty(const struct Queue* pq)
{
	return pq->front == pq->rear;
}

int enQueue(struct Queue* pq, int x)
{
	if (isFull(pq))
	{
		return 0;
	}
	else
	{
		pq->data[pq->rear] = x;
		pq->rear = (pq->rear + 1) % (pq->capacity + 1);
		return 1;
	}
}

int deQueue(struct Queue* pq, int* px)
{
	if (isEmpty(pq))
	{
		return 0;
	}
	else
	{
		*px = pq->data[pq->front];
		pq->front = (pq->front + 1) % (pq->capacity + 1);
		return 1;
	}
}

int main()
{
	struct Queue q;
	init(&q, 5);
	enQueue(&q, 11);
	enQueue(&q, 11);
	return 0;
}