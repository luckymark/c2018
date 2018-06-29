#include <stdio.h>
#include <stdlib.h>
#define N 15
#define FINDNUM 5
struct slist {
	int info;
	struct slist *next;
};
int a[N]={0,1,5,1,2,32,3,5,4,54,6,5,8,54,5};
typedef struct slist Slist;
int findnumber(int nub,Slist *list);
int count=0;
Slist *change;
int main()
{
	Slist *head,*p,*cp;
	head=NULL;
	int i;
	//遍历链表
	for (i=N-1;i>=0;i--)
	{
		p=(Slist *)malloc(sizeof(Slist));
		p->info=a[i];
		if (head==NULL)
		{
			head=p;
			p->next=NULL;
		}
		else
		{
			 p->next=head;
			 head=p;
		}	
	}
	cp=head;
	change=head;
	printf("遍历链表：\n");
	while (head!=NULL)
	{
		printf("%d  ",head->info);
		head=head->next;
	}
	printf("\n\n\n"); 
	//在链表中寻找数据
	int number=findnumber(FINDNUM,change);
	i=1;
	printf("寻找数据：\n");
	printf("您要找的数据为%d\n",FINDNUM);
	while (number!=-1)
	{
		printf("第%d个%d在链表的第%d个结点出现\n",i,FINDNUM,number);
		i++;
		change=change->next;
		number=findnumber(FINDNUM,change);
	}
	if (i==1)
	{
		printf("链表中没有此数据\n");
	}
	printf("\n\n\n");
	//与链表反序
	Slist *trans=NULL,*q;
	while(cp!=NULL)
	{
		q=(Slist *)malloc(sizeof(Slist));
		q->info=cp->info;
		if(trans==NULL)
		{
			trans=q;
			q->next=NULL;
		}
		else
		{
			q->next=trans;
			trans=q;	
		}
		cp=cp->next;
	}
	printf("链表反序：\n");
	while (trans!=NULL)
	{
		printf("%d  ",trans->info);
		trans=trans->next;
	}
	printf("\n");
	return 0;
} 
int findnumber(int nub,Slist *list)
{
	int found=-1;
	while (list!=NULL)
	{
		count++;
		if (list->info==nub)
		{
			found=count;
			break;
		}
		change=change->next;
		list=list->next;
	}
	return found;
}
