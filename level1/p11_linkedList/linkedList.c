#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	int data;
	struct node *next;
}NODE;

void Reverse(NODE* list){
    if (list != NULL){
        if (list->next != NULL){
            Reverse(list->next);
        }
        printf("%d.%d \n",list->num,list->data);
    }
}

int main(){
	int i = 1;
	NODE *p1,*phead,*p2;
	p1 = (NODE *)malloc(sizeof(NODE));
	printf("please input your num(0 is out)\n");
	scanf("%d",&p1->data);
	phead = NULL;
	
	while(p1->data != 0){
		if(phead == NULL){
			phead = p1;
		}else{
		p2 = p1;
		p1 = (NODE *)malloc(sizeof(NODE));
		scanf("%d",&p1->data);
		p2->next = p1;
		p2->num = i;
		i++;
		}
	}
	
	p1->next = NULL;
	p1 = phead;
	while(p1->next != NULL){
		printf("%d : %d\n",p1->num,p1->data);
		p1 = p1->next;
	}
	
	p1 = phead;
	Reverse(p1);
	p1 = phead;
	
	i = -1;
	while(p1->next != NULL){
		if(p1->data == 5){
			printf("%d\n",p1->num);
			i = 1;
		}
		p1 = p1->next;
	}
	if(i == -1){
		printf("%d",i);
	}
	return 0;
}
