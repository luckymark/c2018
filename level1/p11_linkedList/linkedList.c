#include<stdio.h>
#include<stdlib.h>

struct numlist{
	int value;                     
	struct numlist* next;
};

struct numlist *relist(struct numlist *head);
void cleanup(struct numlist *head);

int main(void){
	struct numlist* head=NULL;
	struct numlist* prev,*now;
	int cnt;                                   //暂存value的值 
	while(1){
		char c;
		if ((c=getchar())=='\n'){
			break;
		} 
		cnt=c-'0';
		while ((c=getchar())!='\n'){
			cnt=cnt*10+c-'0';
		} 
		now=(struct numlist* )malloc(sizeof(struct numlist));
		if( head == NULL){
			head = now;
		}else{
			prev->next = now;
		}
		now->next = NULL;
		now->value = cnt;
		prev=now;
	}
	
	struct numlist *temp=relist(head);                 //逆序链表 
	int num=1;
	int status=0;
	now=temp;
	while(now){
	if(now->value == 5){
		status=1;
		printf("%d ",num);
	}
	now=now->next;
	num++;                                            //计数 
	}
	printf("\n");
	
	if(status == 1){
		printf("Above is the order of list which's value equals 5!\n");
	}else{
		printf("-1 \n");
	}
	cleanup(head);	                                  //清理malloc的内存 
	return 0;
}

struct numlist* relist(struct numlist *head){
	struct numlist *Prev,*Now,*Next;
	struct numlist *rhead;
	Prev=NULL;
	Now=head;
	Next=head->next;
	while(Next){
		Now->next=Prev;
		Prev=Now;
		Now=Next;
		Next=Next->next;
	}
	Now->next=Prev;
	rhead=Now;
	
	return rhead;
}

void cleanup(struct numlist *head){
	struct numlist *now=head;
	while(now){
		free(now);
		head=now->next;
	}
}
