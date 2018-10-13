#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
} node;

node *create(int n) {
	node *head, *p, *pNext;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	pNext = head;
	for (int i = 1; i <= n; ++i) {
		printf("请输入第%d个数据:", i);
		p = (node *)malloc(sizeof(node));
		scanf_s("%d", &p->data);
		p->next = NULL;
		pNext->next = p;
		pNext = p;
	}
	return head;
}

void show(node *head) {
	node *tail;
	tail = head->next;
	while (tail != NULL)
	{
		if (tail->next != NULL)
		{
			printf("%d ", tail->data);
		}
		else
		{
			printf("%d\n", tail->data);
		}
		tail = tail->next;
	}
}

node *reverse(node *head) {
	node *current, *pnext, *prev;
	if (head == NULL || head->next == NULL)
		return head;
	current = head->next;
	pnext = current->next;
	current->next = NULL;
	while (pnext)
	{
		prev = pnext->next;
		pnext->next = current;
		current = pnext;
		pnext = prev;
	}
	head->next = current;
	return head;
}

void search(node *head,int n) {
	node *current;
	current = head;
	int count = 0;
	int flag = 0;
	while (current) {
		if (current->data == n) {
			printf("%d ", count);
			flag = 1;
		}
		count++;
		current = current->next;
	}
	if (flag = 0) {
		printf("-1");
	}
}

int main() {
	printf("请输入节点个数:");
	int n;
	scanf_s("%d", &n);
	node *head;
	head = create(n);
	show(head);
	reverse(head);
	show(head);
	printf("请输入要查找的数:");
	scanf_s("%d",&n);
	search(head, n);
	system("pause");
}