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
	printf("��������Ҫ�����Ľڵ����\n");
	scanf_s("%d", &count);
	node*head = Creatlist(1);
	node*temp = head->next;
	Addpoint(head, count);
	while (temp->next != NULL)
	{
		printf("��%d���ڵ��ֵΪ%d\n",i,temp->data);
		temp = temp->next;
		i++;
	}
	printf("���跴ת����������1\n");
	scanf_s("%d", &judge);
	if (judge)
	{
		head = reverseList(head);
	}
	temp = head->next; i = 1;
	while (temp->next != NULL)
	{
		printf("��%d���ڵ��ֵΪ%d\n", i, temp->data);
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
	if (H == NULL || H->next == NULL) //����Ϊ�ջ��߽�1����ֱ�ӷ���
		return H;
	node* p = H, *newH = NULL;
	while (p != NULL)                 //һֱ��������β
	{
		node* tmp = p->next;          //�ݴ�p��һ����ַ����ֹ�仯ָ��ָ����Ҳ�����������
		p->next = newH;               //p->nextָ��ǰһ���ռ�
		newH = p;                     //�������ͷ�ƶ���p������һ������
		p = tmp;                   //pָ��ԭʼ����pָ�����һ���ռ�
	}
	return newH;
}