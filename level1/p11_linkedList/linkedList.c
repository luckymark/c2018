#include <stdio.h>
#include <stdlib.h>
struct node{
	int xuhao;
	int value;
	struct node * next;
}; 
int chazhao(struct node*,int);
int main(void){
	int i=0,j,num;
	struct node *head,*p1,*p2,*p3;
	printf("����������ڵ��ֵ������-1ֹͣ\n");
	head=(struct node*)malloc(sizeof(struct node));
	p1=head;
	while(1)
	{
		scanf("%d",&(p1->value));
		if(p1->value==-1)
		{
			p3->next=NULL;
			break;	
		}
		else
		{
			p1->xuhao=++i;
			p2=(struct node*)malloc(sizeof(struct node));
			p1->next=p2;
			p3=p1;
			p1=p2;
		}
	}
	p1=head;
	while(p1!=NULL)
	{
		printf("��%d��:%d \n",p1->xuhao,p1->value);
		p1=p1->next;
	}
	printf("��ʼ����\n");
	p1=head->next;
	p2=head;
	head->next=NULL;
	head->xuhao=i;
	while(p1!=NULL)
	{
		p3=p1->next;
		p1->next=p2;
		p1->xuhao=i-p1->xuhao+1;
		p2=p1;
		p1=p3;
	}
	head=p2;
	p1=head;
	while(p1!=NULL)
	{
		printf("��%d��:%d \n",p1->xuhao,p1->value);
		p1=p1->next;
	}
	p1=head;
	printf("���ڿ�ʼ����5\n");
	num=chazhao(p1,5);
	printf("%d ",num);
	if(num!=-1)
		for(j=0;j<num;j++)
		{
			p1=p1->next;
		}
	num=chazhao(p1,5);
	printf("%d ",num);
	return 0;
}
int chazhao(struct node *p,int mubiao){
	while(p!=NULL)
	{
		if(p->value==mubiao)
		{
			return p->xuhao;
		}
		else
			p=p->next;
	}
	return -1;
}
