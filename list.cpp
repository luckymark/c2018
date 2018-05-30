#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}node,*linklist;

linklist creatlinklist(int n)
{
	linklist head=(linklist)malloc(sizeof(node));
	linklist p,q;
	head->data=n;
	q=head;
	for(int i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(node));
		scanf("%d",&p->data);
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;
}
void traverse(linklist q)
{
	while(q->next){
		printf("%d",q->next->data);
		q=q->next;
	}
}
linklist reverse(linklist head)
{
	linklist q= head->next,p=NULL;
	head->next=NULL;
	while(q)
	{
		head->data=q->data;
		p=q->next;
		q->next=head;
		head=q;
		q=p;
	}
	return head;
	
}
linklist search(linklist head,int n)
{
	linklist q=head->next;
	int m;
	m=n;
    int a=-1;
	while(q)
	{
		if(q->data==5)
		{
			printf("序号为%3d",m);
			m--;
			
		}
		if(q->data!=5)
		{
		printf("%3d",a);
		m--;
		}
		q=q->next;
	}
	
	
}
int main(){
	int n;
	printf("链表节点个数：");
	scanf("%d\n",&n);
	linklist head=creatlinklist(n);
	printf("创建后历遍：\n");
	traverse(head); 
	printf("\n节点倒序后：\n");
	head=reverse(head);
	traverse(head);
	printf("\n");
	printf("节点为5返回所在序号，否则返回-1\n");
	search(head,n);
}
