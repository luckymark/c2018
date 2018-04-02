#include<stdio.h>  
#include<stdlib.h>
  
  
typedef struct LNode
{  
    int value;  
    struct LNode *next;  
}LNode,*linkList;  
  
linkList creatLinkList(int n)
{
    linkList head = (linkList)malloc(sizeof(LNode));  
    linkList p,q;  
    head->value=n; 
    q = head;  
    for(int i = 0;i < n;i++) {  
        p = (linkList)malloc(sizeof(LNode));  
        scanf("%d",&p->value);  
        q->next = p;  
        q = p;  
    }  
    q->next = NULL;  
    return head;  
}  
  
void listTraverse(linkList q)
{  
    while(q->next) {  
        printf("%d ",q->next->value);  
        q = q->next;  
    }  
}  
  
linkList reverseLinkList(linkList head)
{  
    linkList q= head->next,p = NULL;  
    head->next = NULL;  
    while(q)  
    {  
       head->value=q->value;   
        p = q->next;   
        q->next = head;   
        head= q;   
        q = p;  
    }   
    return head;  
} 

linkList search(linkList head,int n)
{
	linkList q=head->next;
	int m;
	m=n;
	while(q)
	{
		
		if(q->value==5)
		{
			printf("%d ",m);
			m--;
		}
		if(q->value!=5)
		{
			m--;
			printf("-1 ");
		}
		q=q->next;
	}
}
  
int main() {  
	int n;
	printf("����ڵ������");
	scanf("%d\n",&n); 
    linkList head = creatLinkList(n);  
    printf("�����������\n");  
    listTraverse(head);  
    printf("\n������ת�ú�\n");  
    head = reverseLinkList(head);  
    listTraverse(head);  
    printf("\n");
    printf("�ڵ�Ϊ5����������ţ����򷵻�-1\n");
    search(head,n);
} 
















