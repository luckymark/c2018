#include <stdio.h>
#include <stdlib.h>       
#include <string.h>

typedef struct information{     //������Ϣ
    char number[20];        //���
    int count;           //����   
    struct information *next;  
}inf;
          
void menu(inf *head);                            //��ʾ���˵�
inf *create();                                   //��������
void output(inf *head);                          //���������Ϣ
void set(int n,inf *head);                       //����������Ϣ
void add(inf *head);                             //���ӻ�����Ϣ
void del(inf *head);                             //ɾ��������Ϣ
void write_file(inf *head);                      //���������Ϣ���ļ�
void freeh(inf *head);                           //�˳�����

void menu(inf *head){                                 //��ʾ�˵�
    printf("welcome to the list\n");
    printf("1. show the list\n");
    printf("2. add the new information\n");
    printf("3. add\n");
    printf("4. del\n");
    printf("5. out\n");
    printf("please input your num(1~5):\n");
}

inf *create(){                                   //��������
    inf *p;
    p = (inf *)malloc(sizeof(struct information));
    if(p == NULL){  
    	printf("create file\n");
        exit(0);
    }
    p->next = NULL;
    return (p);
}

void output(inf *head){                              //���������Ϣ
    inf *p;
    p = head->next;
    if(p == NULL){
        printf("NONE!please input the information\n");
        return;
    }
    while(p != NULL){
       printf("information��num: %s��count:%d \n",p->number,p->count);
       p = p->next;
    }
}

void set(int n,inf *head){                   //����������Ϣ
    inf *p;
    int i;
    printf("how many groups of information do you want to add:\n");
    scanf("%d",&n);
    for(i = 1;i <= n;i++){
    	p = (inf *)malloc(sizeof(struct information));
        if(p == NULL){  
    		printf("create file\n");
    		exit(0);
        }
        printf("please input:num��count��\n");  
        printf("num:");  
        scanf("%s",p->number);
        printf("count:");  
        scanf("%d",&p->count);  
        p->next = NULL;  
        while(head->next != NULL)  
            head = head->next;  
        head->next = p;  
    }  
}

void add(inf *head){                       //���ӻ�����Ϣ
    char number[20];  
    int i = -1;
    int m;
    inf *p;  
    p = head;  
    printf("please input which one do you want to move in��\n");  
    scanf("%s",number);  
    while(p->next != NULL){  
        if(strcmp(number,p->next->number) == 0){     
            i = 1;
            printf("please input how many dou you want to move in:\n");
            scanf("%d",&m);
            p->next->count = p->next->count + m;
            printf("add successfully\n");  
            break;  
        }  
        p = p->next;  
    }
    if(i < 0)  
    printf("NONE information!\n");
}
      
void del(inf *head){                       //ɾ��������Ϣ
    char number[20];  
    int i = -1;
    int m;
    inf *p;  
    p = head;  
    printf("please input which one do you want to move out��\n");  
    scanf("%s",number);  
    while(p->next != NULL){  
        if(strcmp(number,p->next->number) == 0){     
            i = 1;
            printf("please input how many dou you want to move out:\n");
            scanf("%d",&m);
            p->next->count = p->next->count - m;
            printf("delete successfully\n");  
            break;  
        }  
        p = p->next;  
    }
    if(i < 0)  
    printf("NONE information!\n");
}
          
void write_file(inf *head){                          //���������Ϣ���ļ�
    inf *p;  
    FILE *fp;  
    p = head;  
    if((fp = fopen("information.txt","wb")) == NULL){
        printf ("Do not have this file\n");
        exit(0);
    }
    while(p->next != NULL){
        p = p->next;
        fwrite(p,sizeof(struct information),1,fp);
    }  
    fclose(fp);  
}  

void freeh(inf *head){                              //�ͷſռ� �˳�����
    inf *p;  
    p = (inf *)malloc(sizeof(struct information));  
    p = head;  
    while(head->next != NULL){  
        head = head->next;  
        free(p);  
        p = head;  
    }
	free(p);  
}  
  
int main(){  
    inf *head;  
    head = (inf*)malloc(sizeof(struct information));  
    head = create();  
    while(1){  
        menu(head);
        int h,i;
        scanf("%d",&h);
        switch(h){
            case 1:
                output(head);  
                break;  
            case 2:
            	set(i,head);
            	write_file(head);
            	break;
            case 3:  
                add(head);
                write_file(head);
                break;  
            case 4:      
                del(head);   
                write_file(head);
                output(head);
                break;  
            case 5:  
                freeh(head);  
                printf("out successfully\n");  
                exit(0);  
            default:      
                printf("wrong\n");  
                break;  
        }  
    }
}  
