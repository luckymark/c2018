#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}node;

node *head,*p,*r;

void node_creat(int n){
	int i;
	head=malloc(sizeof(node));
	head->next=NULL;
	r=head;   
	for(i=1;i<=n;i++){
		p=malloc(sizeof(node));
		printf("please enter the value of the %dth node\n",i);
		scanf("%d",&p->value);
		p->next=NULL;
		r->next=p;
		r=p; 
	} 
}

void node_add(int a,int k){
	int j=0;
	p=head;
	while(p->next!=NULL&&j<=a){  
        p=p->next;  
        j++;  
    }
	r=malloc(sizeof(node));
	r->value=k;
	r->next=p->next;
	p->next=r;
} 

void node_enquire(int n){
	int j=0;
	p=head->next;
	while(p->next!=NULL&&j<=n){
		p=p->next;
		j++;
	}
	printf("the value of the node is : %d\n",p->value);
	system("pause");
}

void node_delete(int a){
	int j=0;
	p=head;
	while(p->next!=NULL&&j<a-1){
		p=p->next;
		j++; 
	}
	r=p->next;
	p->next=r->next;
	free(r);
}

void node_inverse(){
	p=head->next;
	while(p->next!=NULL){
		r=p->next;
		p->next=r->next;		//先将编号1的结点指向后面第二个节点 
		r->next=head->next;		//再把后面第二个节点指向链表第一个节点 
		head->next=r;			//最后将头节点指向r 
	}
} 

void node_find(int a){
	int count=1,flag=0;
	p=head->next;
	while(p->next!=NULL){
		if(p->value==a){
			printf("%dth node is %d\n",count,a);
			flag=1; 
		}
		p=p->next;
		count++;
	} 
	if(p->value==a){
		flag=1;
		printf("%dth node is %d\n",count,a);
	}
	if(flag==0){
		printf("-1\n");
	}
}

int main(){
	int flag,N=0,cas,x,y,i,f;
	while(1){
	printf("1. Creat\n2. Enquire\n3. Add\n4. Delete\n5. Display\n6. Inverse\n7. Find\n");
	scanf("%d",&cas);
	system("cls");
	switch(cas){
	case 1:
		printf("How much node do you need?\n");
		scanf("%d",&N);
		node_creat(N);	
		break;
	case 2:
		printf("Which node do you wanna enquire?\n");
		scanf("%d",&x);
		node_enquire(x);
		break;
	case 3:
		printf("Where do you want to add behind? (If you input zero, you will add at the first node)\n");
		scanf("%d",&x);
		printf("What is the value of the new node?\n");
		scanf("%d",&y);
		node_add(x,y);
		break;
	case 4:
		printf("Which node do you want to delete?\n");
		scanf("%d",&x);
		node_delete(x);
		N--;
		break;
	case 5:
		if(N==0){
			printf("Nothing exist!\n");
			system("pause");
			break;
		}
		p=head->next;
		int count=1;
		while(p->next!=NULL){
			printf("%dth node : %d\n",count,p->value);
			p=p->next;
			count++;
		}
		printf("%dth node : %d\n",count,p->value);
		system("pause");
		break; 
	case 6:
		node_inverse();
		printf("Inverse complete!\n");
		system("pause");
		break;
	case 7:
		printf("Which number do you wanna find?\n");
		scanf("%d",&f);
		node_find(f);
		system("pause");
		break;
	default:
		printf("Illegal input!");
		system("pause");
		break;
	}
	system("cls");
	}
} 
