#include <stdio.h>
#include <stdlib.h>

//定义链表数据结构 
struct node
{
	int no;
	int num;
	struct node *next;
};
int find5=0;

struct node *creat();
void print();
struct node *obs();
int findfive();

int main()
{
	int a1,a2;
	struct node *head;
	head=NULL; //建一个空表 
	head=creat(head);//创建单链表 
//	head=obs(head);    //反向 
	print(head);   //输出链表的值 
	a1=findfive(head);    //查找5
	a2=findfive(head);    //再查找5
	printf("%d %d",a1,a2);
	getchar();
    return 0;
}

struct node *creat(struct node *head)
{
	struct node *p1,*p2;
	int i=1;
	//利用malloc()申请分配节点
	p1=p2=(struct node*)malloc(sizeof(struct node));//新节点
	printf("请输入值，值小于等于0结束，值存放地址为：p1_ADDR= %d\n",p1); 
    scanf("%d",&p1->num);
    p1->no=i;
    p1->next=NULL;
    while(p1->num>0)  //输入的节点数值大于0
	{
		if(head==NULL)
			head=p1;  //空表，接入表头
		else
			p2->next=p1;  //非空表，接到表尾
		p2=p1;
		
		p1=(struct node*)malloc(sizeof(struct node));//下一个新节点
		i=i+1; 
   		printf("请输入值，值小于等于0结束，值存放地址为：p%d_ADDR= %d\n",i,p2); 
   		scanf("%d",&p1->num);//输入节点的值
   		p1->no=i;
   		//判断一下是否有后续节点要接入链表，若无则结束;  
	}
	free(p1); //申请到的没录入，所以释放掉  
 	p1=NULL;  //使指向空  
  	p2->next = NULL; //到表尾了，指向空  
  	printf("链表输入结束（END）\n");  
	return head;/*返回链表的头指针*/
}

void print(struct node *head)/*出以head为头的链表各节点的值*/
{ 
    struct node *temp; 
    temp=head;/*取得链表的头指针*/
  
    printf("\n\n\n链表存入的值为：\n"); 
    while(temp!=NULL)/*只要是非空表*/
    { 
 	    printf("%6d\n",temp->num);/*输出链表节点的值*/
    	temp=temp->next;/*跟踪链表增长*/
    }
  	printf("链表打印结束!!"); 
} 

struct node *obs(struct node *head)
{
	struct node *temp,*x1,*x2;
	temp=head->next;
	if(head==NULL)
		return head;
	head->next=NULL;
	x1=temp->next;   //拿到下一个地址(此处第三个) 
	temp->next=head;
	while(1)
	{
		if(x1->next==NULL)
		{
			x1->next=temp;
			temp=x1;
			return temp;
		}
		x2=x1;
		x1=x1->next;
		x2->next=temp;
		temp=x2;
	}
}

int findfive(struct node *head)
{
	struct node *temp;
	temp=head;    //取头指针 
	while(temp->next!=NULL)
	{
		if(temp->num==5 && temp->no>find5)
		{
			find5=temp->no;
			return temp->no;
		}
		temp=temp->next;
	}
	if(temp->num==5)
	{
		return temp->no;
	}
	return -1;
}
