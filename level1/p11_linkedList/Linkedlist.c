#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*next;
};
typedef struct Node node;
node* Creatlist(int data);
void Addpoint(node* head,int count);
node* reverseList(node* H);
int main(void)
{
	int count,i,judge;
	i = 1;
	printf("请输入需要创建的节点个数\n");
	scanf_s("%d", &count);
	node*head = Creatlist(1);
	node*temp = head->next;
	Addpoint(head, count);
	while (temp->next != NULL)
	{
		printf("第%d个节点的值为%d\n",i,temp->data);
		temp = temp->next;
		i++;
	}
	printf("如需反转链表请输入1\n");
	scanf_s("%d", &judge);
	if (judge)
	{
		head = reverseList(head);
	}
	temp = head->next; i = 1;
	while (temp->next != NULL)
	{
		printf("第%d个节点的值为%d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
	system("pause");
	return 0;

}
node* Creatlist(int data)
{
	node*head = NULL;
	head = (node*)malloc(sizeof(node));
	head->next = (node*)malloc(sizeof(node));
	head->next->data = data;
	head->next->next = NULL;
	return head;
}
void Addpoint(node* head,int count)
{
	node*temp = head->next;
	while (count)
	{
		temp->data = count;
		temp->next = (node*)malloc(sizeof(node));
		temp = temp->next;
		temp->next = NULL;
		count--;
	}
}
node* reverseList(node* H)
{
	if (H == NULL || H->next == NULL) //链表为空或者仅1个数直接返回
		return H;
	node* p = H, *newH = NULL;
	while (p != NULL)                 //一直迭代到链尾
	{
		node* tmp = p->next;          //暂存p下一个地址，防止变化指针指向后找不到后续的数
		p->next = newH;               //p->next指向前一个空间
		newH = p;                     //新链表的头移动到p，扩长一步链表
		p = tmp;                   //p指向原始链表p指向的下一个空间
	}
	return newH;
}