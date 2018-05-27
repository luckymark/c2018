#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	int id;
	struct node *next;

}node;  
typedef struct list {
	node *pHead;
}list;

void InitHead(node * *pHead){
	*pHead = (node*)malloc(sizeof(node));
	if (*pHead == -1) { 
		printf("·ÖÅäÊ§°Ü£¬boom!"); 
     	exit(-1); }
}
void FreeList(node*pHead){
	node*p;
	while (pHead != NULL)
	{
		p = pHead;
		pHead = pHead->next;
		free(p);
		p =NULL;
	}
}
void append(node *pHead, int number) {
	node *q = pHead;
	node* pNew = (node*)malloc(sizeof(node));//create a new node
	pNew->data = number;
	pNew->next = NULL;
	
	if (!pNew ) {
		printf("ÅäÖÃÐÂ½ÚµãÊ§°Ü£¬boom!\n");
		exit(-1);
	}
	while (q->next) {
		q = q->next;
	}
	
	q->next = pNew;
	q = pNew;
}
void showList(node*pHead) {
	pHead = pHead->next;
	while (pHead != NULL) {
		printf("%d", pHead->data);
		pHead = pHead->next;

	}
}
void reverse(node *pHead) {
	node *p = pHead,
		*q = p->next,
    	*r = NULL;
	if (q) {
		r = q->next;
		pHead->next = NULL;

	}
	else
		return pHead;
	while (1)
	{
		q->next = p;
		if (r) {
			p = q;
			q = r;
			r = r->next;
		}
		else
			return q;
	}
}
int search(list*pHead,int number) {
	node*p; int found = -1;
	for (p = pHead; p; p = p->next) {
		if (p->data == 5) {
			printf("find it!");
			found = 1;
			continue;
		}
		else {
			printf("NOT FOUND!");
			return found;
		}
	}
}
int main(void) {
	node*L = NULL;
	InitHead(&L);
	append(L, 1);
	append(L, 6); 
	append(L, 4);
	append(L, 9);
	append(L, 7);
	append(L, 5);
	append(L, 9);
	append(L, 8);
	showList(L);
	reverse(L);
	int a[] = { 1,6,4,9,7,5,9,8 };
	for (int i = 0; i < 8;i++) {
			search(L, a[i]);
	}
	
	FreeList(L);
	L = NULL;
	return 0;


	// time£º5.8 3:30-7:00
	
	
	
}

