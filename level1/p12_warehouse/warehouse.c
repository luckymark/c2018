#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 30
struct Good{
	int num;
	char type[N];
};
struct List{
	struct Good *good;
	struct List *next;
};
struct List *head;
struct List* duqu(char *);
void ruku(char *);
void printlist(void);
void chuku(char *);
int start(void);
void end(char*);
int main(void){
	char fname[20]="goodsinfo";
	head=duqu(fname);
	while(1)
	{
		switch(start())
		{
			case 2:
				printlist();
				break;
			case 3:
				ruku(fname);
				printlist();
				break;
			case 4:
				chuku(fname);
				printlist();
				break;
			case 5:
				end(fname);
				break;
		}
	}
	return 0;
}
int start(void){
	int i;
	system("cls");
	printf("��2�鿴������Ϣ\n��3���\n��4����\n��5�˳�\n");
	scanf("%d",&i);
	getchar();
	return i;
}
struct List* duqu(char *fname){
	FILE *fp;
	struct List *p1,*p2;
	int i=0;
	if((fp=fopen(fname,"r"))==NULL)
	{
		printf("�ļ������ڣ�\n");
		exit(EXIT_FAILURE);
	}
	head=(struct List*)malloc(sizeof(struct List));
	head->good=(struct Good*)malloc(sizeof(struct Good));
	p1=p2=head;
	while(fread(p1->good,sizeof(struct Good),1,fp))
	{
		i++;
		p2=(struct List*)malloc(sizeof(struct List));
		p2->good=(struct Good*)malloc(sizeof(struct Good));
		p1->next=p2;
		p2=p1;
		p1=p1->next;
	}
	if(i==0)
	{
		head=NULL;
	}
	else
	{
		free(p1);
		p2->next=NULL;
	}
	fclose(fp);
	printf("������%d�ֻ�����Ϣ\n",i);
	return head;
}
void printlist(void){
	struct List *p1=head;
	while(p1!=NULL)
	{
		printf("�����ͺ�:%s ����%d\n",p1->good->type,p1->good->num);
		p1=p1->next;
	}
	printf("��������ص���ҳ��\n");
			getch();
}
void ruku(char * fname){
	char goodtype[N];
	struct List *p1,*p2;
	int goodnum,typenum,i,cunzai;
	system("cls");
	printf("Ҫ��⼸�ֻ��\n");
	scanf("%d",&typenum);
	printf("�������������������\n");
	for(i=0;i<typenum;i++)
	{
		p1=head;
		cunzai=0;
		scanf("%s %d",goodtype,&goodnum);
		while(p1!=NULL)
		{
			if(strcmp(goodtype,p1->good->type)==0)
			{
				p1->good->num+=goodnum;
				cunzai=1;
				break;
			}
			p1=p1->next;	
		}
		if(cunzai)
			continue;
		else
		{
			p2=(struct List*)malloc(sizeof(struct List));
			p2->good=(struct Good*)malloc(sizeof(struct Good));
			strcpy(p2->good->type,goodtype);
			p2->good->num=goodnum;
			p2->next=head;
			head=p2;
		}					
	}
}
void chuku(char * fname){
	char goodtype[N];
	struct List *p1,*p2;
	int goodnum,typenum,i,cunzai;
	system("cls");
	printf("Ҫ���⼸�ֻ��\n");
	scanf("%d",&typenum);
	printf("����������������������\n");
	for(i=0;i<typenum;i++)
	{
		p1=p2=head;
		cunzai=0;
		scanf("%s %d",goodtype,&goodnum);
		getchar(); 
		while(p1!=NULL)
		{
			if(strcmp(goodtype,p1->good->type)==0)
			{
				cunzai=1;
				if(goodnum>p1->good->num)
				{
					printf("%s����ʧ�ܣ���������\n",p1->good->type);
					i--;
					break;
					getch();
				}
				else
				{
					p1->good->num-=goodnum;
					if(p1->good->num==0)
					{
						p2->next=p1->next;
						free(p1);
					}
				}
				break;
			}
			p2=p1;
			p1=p1->next;	
		}
		if(cunzai)
			continue;
		else
		{
			printf("%s���ڿ���У�\n",goodtype);
			getch();
		}					
	}
}
void end(char *fname){
	FILE *fp;
	struct List *p1=head;
	if((fp=fopen(fname,"w"))==NULL)
	{
		printf("�ļ���ʧ�ܣ��޷��������ݣ�\n");
		exit(EXIT_FAILURE);
	}
	while(p1!=NULL)
	{
		fwrite(p1->good,sizeof(struct Good),1,fp);
		p1=p1->next;
	}
	fclose(fp);
	exit(0);
}
