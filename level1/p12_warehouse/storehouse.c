#include <stdio.h>
#include <stdlib.h>
#define maxn 10000
int amount,c,d,e;
int judge=0;
typedef struct 
{
	int number;
	int action;
	char name[100];
	int amount;
}item;
item it[maxn];

void begin();
void menu(); 
void display();

int main(int argc, char *argv[]) 
{
	begin();
	while(1)
	{
		menu();
		if(1==judge)break;
	} 
	update();
	printf("see you!\n") ;
	return 0;
}

void begin()
{
	FILE *fp=fopen("warehouse.txt","r");
	int i;
	for(i=1;i<=maxn;i++)
	{
		if((fscanf(fp,"%d%s%d",&it[i].number,it[i].name,&it[i].amount))!=3)
		break;
		it[i].action=1;
	}
	fclose(fp);
}

void menu()
{
	system("cls");
	printf("�˵�\n1����ʾ����б�\n2�����\n3������\n4���˳�����\n���������ѡ��\n");
	int choice=0;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			display();
			break;
		case 2:
			import();
			break;
		case 3:
			export();
			break;
		case 4:
			judge=1;
		default:
			break;
	}
}
void update()
{
	FILE *fp;
	fp=fopen("warehouse.txt","w");
	int i;
	for(i=1;i<=maxn;i++)
	{
		if(it[i].action==1)
		fprintf(fp,"%d %s %d\n",it[i].number,it[i].name,it[i].amount);
	}
	fclose(fp);
}


void display()
{
	
	system("cls");
	int i;
	for(i=1;i<maxn;i++)
	{
		if(it[i].action==1)
		printf("%d %s %d\n",it[i].number,it[i].name,it[i].amount);
	}
	printf("press any key to continue\n");
	getch();
}
void import()
{
	printf("������\n");
	scanf("%d",&c);
	it[c].action=1;
	it[c].number=c;
	printf("��������Ҫ����Ļ�������\n");
	scanf("%s",&it[c].name);
	printf("��������\n");
	scanf("%d",&it[c].amount);
 } 
 
 void export()
 {
	printf("������\n");
	scanf("%d",&c);
	printf("��Ҫȡ���Ļ�������:%s\n",it[c].name);
	printf("����ȡ������\n");
	scanf("%d",&d);
	it[c].amount-=d;
	return;
 }
