#include <stdio.h>
#include <stdlib.h>

//�����������ݽṹ 
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
	head=NULL; //��һ���ձ� 
	head=creat(head);//���������� 
//	head=obs(head);    //���� 
	print(head);   //��������ֵ 
	a1=findfive(head);    //����5
	a2=findfive(head);    //�ٲ���5
	printf("%d %d",a1,a2);
	getchar();
    return 0;
}

struct node *creat(struct node *head)
{
	struct node *p1,*p2;
	int i=1;
	//����malloc()�������ڵ�
	p1=p2=(struct node*)malloc(sizeof(struct node));//�½ڵ�
	printf("������ֵ��ֵС�ڵ���0������ֵ��ŵ�ַΪ��p1_ADDR= %d\n",p1); 
    scanf("%d",&p1->num);
    p1->no=i;
    p1->next=NULL;
    while(p1->num>0)  //����Ľڵ���ֵ����0
	{
		if(head==NULL)
			head=p1;  //�ձ������ͷ
		else
			p2->next=p1;  //�ǿձ��ӵ���β
		p2=p1;
		
		p1=(struct node*)malloc(sizeof(struct node));//��һ���½ڵ�
		i=i+1; 
   		printf("������ֵ��ֵС�ڵ���0������ֵ��ŵ�ַΪ��p%d_ADDR= %d\n",i,p2); 
   		scanf("%d",&p1->num);//����ڵ��ֵ
   		p1->no=i;
   		//�ж�һ���Ƿ��к����ڵ�Ҫ�����������������;  
	}
	free(p1); //���뵽��û¼�룬�����ͷŵ�  
 	p1=NULL;  //ʹָ���  
  	p2->next = NULL; //����β�ˣ�ָ���  
  	printf("�������������END��\n");  
	return head;/*���������ͷָ��*/
}

void print(struct node *head)/*����headΪͷ��������ڵ��ֵ*/
{ 
    struct node *temp; 
    temp=head;/*ȡ�������ͷָ��*/
  
    printf("\n\n\n��������ֵΪ��\n"); 
    while(temp!=NULL)/*ֻҪ�Ƿǿձ�*/
    { 
 	    printf("%6d\n",temp->num);/*�������ڵ��ֵ*/
    	temp=temp->next;/*������������*/
    }
  	printf("�����ӡ����!!"); 
} 

struct node *obs(struct node *head)
{
	struct node *temp,*x1,*x2;
	temp=head->next;
	if(head==NULL)
		return head;
	head->next=NULL;
	x1=temp->next;   //�õ���һ����ַ(�˴�������) 
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
	temp=head;    //ȡͷָ�� 
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
