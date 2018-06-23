#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(Stu)

typedef struct Student{
	long num;
	float score;
	struct Student *next;
}Stu;

int n;
Stu * creat();
void print(Stu *head);
Stu * reverse(Stu *head);
int search(Stu *head,int t);

int main(){
	int t=0;
	Stu *pt = creat();//创建链表 
	printf("\n");
	print(pt);
	pt = reverse(pt);//反转链表 
	printf("\nreverse:\n");
	print(pt);
	printf("\n");
	t = search(pt,t);//查找第一个满足要求的节点 
	printf("%d ",t);
	t = search(pt,t);//查找下一个满足要求的节点 
	printf("%d ",t);
	return 0;
}

Stu * creat() {
	Stu *head = NULL, *p1 = NULL, *p2 = NULL;
	p1 = p2 = (Stu *) malloc(LEN);
	scanf("%ld %f",&p1 -> num,&p1 -> score);
	while (p1 -> num != 0){
		n++;
		if (n == 1){
			head = p1;
		}
		else{
			p2 -> next = p1;
		}
		p2 = p1;
		p1 = (Stu *) malloc(LEN);
		scanf("%ld %f",&p1 -> num,&p1 -> score);
	}
	p2 -> next = NULL;
	return head;
}

void print(Stu *head){
	Stu *p = head;
	while (head != NULL){
		printf("%ld %.1f\n",p -> num,p -> score);
		if (p -> next == NULL) {
			break;
		}
		p = p -> next;
	}
}

Stu * reverse(Stu *head)  {  
    /*递归法 
	if (head == NULL || head -> next == NULL)  {     
        return head;  
    }     
    Stu *p = head -> next;  
    Stu *newhead =  reverse(p);  
    p -> next = head;  
    head -> next = NULL;  
    return newhead; */
    
	Stu *cur = head, *temp = head;
	if ((cur -> next) != NULL){
		cur = cur -> next;
		temp -> next = NULL;
	}
	while (1){
		temp = cur;
		cur = cur -> next;
		temp -> next = head;
		head = temp;
		if (cur -> next == NULL){
			cur -> next = temp;
			break;
		}
	}
	head = cur;
	return head;
}  

int search(Stu *head,int t){
	int m=0;
	Stu *p = head;
	while(head != NULL){
		m++;
		if((p->score < 60) || (p->next == NULL)){
			if(m>t){
				break;
			}
		}
		p = p -> next;
	}
	if((m>=n)&&(p->score >= 60)){
		return -1;
	}
	return m;
}

