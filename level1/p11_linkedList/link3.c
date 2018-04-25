#include<stdio.h>
#include<stdlib.h>

struct student
{
	int num;
	struct stduent *next;
};

int main()
{ 
	struct student *head,*current,*already;
	current=head=(struct student*)malloc(sizeof(struct student));
	printf("输入0结束\n");
	scanf("%d",&current->num);
	while(current->num!=0)
	{
		already=current;
		current=(struct student*)malloc(sizeof(struct student));
		scanf("%d",&current->num);
		already->next=current;
	}
	current->next=NULL;
	printf("------------------链表数据--------------------\n");
	current=head;
	while(current->next!=NULL)
	{
		printf("%d\n",current->num);
		current=current->next;
	}
	printf("%d\n",current->num);
	printf("------------------节点为5的序号-------------------\n");
	current=head;
	int i=0,g=0;
	while(current->next!=NULL)  
        { 
          	i++;
          	if(current->num==5)
          	{
		  		printf("%d\n",i);
		  		g=g+1;
			}
          	current=current->next;  
        }
    i++;
    if(current->num==5)
    {
		printf("%d\n",i);
		g++;
	}
	if(g==0)
	printf("-1\n"); 
	printf("------------------链表逆序-------------------\n") ;
	struct student *prev,*later;
 	prev=NULL;
 	later=head->next;
 	while(later!=NULL)
 	{
 		head->next=prev;
		 prev=head;
		 head=later;
		 later=later->next;	
	}
	head->next=prev;
	prev=NULL;
	current=head;
	while(current->next!=NULL)
	{
		printf("%d\n",current->num);
		current=current->next;
	}
	printf("%d\n",current->num);
	return 0;
}
