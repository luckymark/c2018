#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N_NODE 100             //假设有100个结点
#define MAX_VALUE 10          //链表中value的最大值
#define MIN_VALUE 0           //链表中value的最小值

int main()
{
	int n = N_NODE;
	int found = 0;
	struct node {
		int value;
		struct node *next;
	} *head, *node_a, *node_b,*inverse, *node_c;
	head = node_a = (struct node *)malloc(sizeof(struct node));
	node_a->value = rand() % ((MAX_VALUE - MIN_VALUE)) + MIN_VALUE;
	for (int i = 0; i < N_NODE; i++)
	{
		node_b = (struct node *)malloc(sizeof(struct node));
		node_a -> next = node_b;
		node_a = node_b;
		node_a->value = rand() % ((MAX_VALUE - MIN_VALUE)) + MIN_VALUE;
	}
	node_a->next = NULL;
	inverse = node_a;
	node_b = inverse;
	for (int i = 0; i < N_NODE; i++,--n)
	{
		node_a = head;
		for (int j = 0; j < n; j++)
		{
			node_a = node_a->next;
		}
		if (i != 0)
		{
			node_b->next = node_a;
			node_b = node_a;
		}
	}
	node_b->next = NULL;
	node_a = inverse;
	printf("序号从0开始计算\n");
	for (int i = 0; i < N_NODE; i++)
	{
		if (i != 0)
		{
			node_a = node_a->next;
		}
		if (node_a->value == 5)
		{
			printf("序号为:%d\n", i);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("-1");
	}
	system("pause");
}