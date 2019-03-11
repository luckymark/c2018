#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef  struct link {
	int data;
	struct link *next;
} node,*pnode;

pnode creat(); 								//����ͷ���
pnode addlist(pnode tail);						//��ӽڵ�
pnode dellist(pnode tail);					//ɾ���ڵ�
void reverse(pnode head);					//������
int search(pnode head,int id,int num);					//����

int main(int argc, char *argv[]) {
	pnode head,tail;
	head=creat();
	tail=head;
	(*head).data=0;
	for (int i=0;i<100;i++) {
		tail=addlist(tail);
		(*tail).data=i;
		
	}
	reverse(head);
	pnode temp;
	temp=tail;
	tail=head;
	head=temp;
	search(head,5,1);
	search(head,5,2);
	
	
	return 0;
}
pnode creat() {
	pnode p=(node *)malloc(sizeof(node));
	(*p).next=NULL;
	return p;
}
pnode addlist(pnode tail) {
	pnode p=(node *)malloc(sizeof(node));
	if(p==NULL) {
		printf("�����ڴ�ʧ�ܡ�");
		return NULL;
	} else {
		(*tail).next=p;
		(*p).next=NULL;
		return p;
	}
}
pnode dellist(pnode head) {
	pnode p,tail;
	for(p=head; (*p).next!=NULL; p=(*p).next) {
		if((*((*p).next)).next==NULL) {
			tail=p;
		}
	}
	free(p);
	p=NULL;
	return tail;
}
int search(pnode head,int id,int num) {
	int count=0;
	for(pnode p=head; (*p).next!=NULL; p=(*p).next) {
		if((*p).data==id) {
			num--;
			if (num==0) {
				printf("%d",count);
				return 1;
			}
		}
		count++;
	}
	printf(" δ�ҵ�"); 
	return -1;
}
void reverse(pnode head) {
	pnode a,b,c;
	a=head;
	b=(*a).next;
	c=(*b).next;
	(*a).next=NULL;
	while (c!=NULL) {
		(*b).next=a;
		a=b;
		b=c;
		c=(*c).next;
	}
	(*b).next=a;
	return;
}
