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
	//��������
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
	printf("��������\n");
	while (head!=NULL)
	{
		printf("%d  ",head->info);
		head=head->next;
	}
	printf("\n\n\n"); 
	//��������Ѱ������
	int number=findnumber(FINDNUM,change);
	i=1;
	printf("Ѱ�����ݣ�\n");
	printf("��Ҫ�ҵ�����Ϊ%d\n",FINDNUM);
	while (number!=-1)
	{
		printf("��%d��%d������ĵ�%d��������\n",i,FINDNUM,number);
		i++;
		change=change->next;
		number=findnumber(FINDNUM,change);
	}
	if (i==1)
	{
		printf("������û�д�����\n");
	}
	printf("\n\n\n");
	//��������
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
	printf("������\n");
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
