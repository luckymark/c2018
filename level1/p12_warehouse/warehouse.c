#include <stdio.h>
#include <stdlib.h>       
#include <string.h>

typedef struct information{     //货物信息
    char number[20];        //编号
    int count;           //数量   
    struct information *next;  
}inf;
          
void menu(inf *head);                            //显示主菜单
inf *create();                                   //创建链表
void output(inf *head);                          //输出货物信息
void set(int n,inf *head);                       //创建货物信息
void add(inf *head);                             //增加货物信息
void del(inf *head);                             //删除货物信息
void write_file(inf *head);                      //保存货物信息到文件
void freeh(inf *head);                           //退出程序

void menu(inf *head){                                 //显示菜单
    printf("welcome to the list\n");
    printf("1. show the list\n");
    printf("2. add the new information\n");
    printf("3. add\n");
    printf("4. del\n");
    printf("5. out\n");
    printf("please input your num(1~5):\n");
}

inf *create(){                                   //创建链表
    inf *p;
    p = (inf *)malloc(sizeof(struct information));
    if(p == NULL){  
    	printf("create file\n");
        exit(0);
    }
    p->next = NULL;
    return (p);
}

void output(inf *head){                              //输出货物信息
    inf *p;
    p = head->next;
    if(p == NULL){
        printf("NONE!please input the information\n");
        return;
    }
    while(p != NULL){
       printf("information：num: %s，count:%d \n",p->number,p->count);
       p = p->next;
    }
}

void set(int n,inf *head){                   //创建货物信息
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
        printf("please input:num，count：\n");  
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

void add(inf *head){                       //增加货物信息
    char number[20];  
    int i = -1;
    int m;
    inf *p;  
    p = head;  
    printf("please input which one do you want to move in：\n");  
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
      
void del(inf *head){                       //删除货物信息
    char number[20];  
    int i = -1;
    int m;
    inf *p;  
    p = head;  
    printf("please input which one do you want to move out：\n");  
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
          
void write_file(inf *head){                          //保存货物信息到文件
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

void freeh(inf *head){                              //释放空间 退出程序
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
