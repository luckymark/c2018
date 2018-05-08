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
	printf("菜单\n1、显示存货列表\n2、入库\n3、出库\n4、退出程序\n请输入你的选择；\n");
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
	printf("输入编号\n");
	scanf("%d",&c);
	it[c].action=1;
	it[c].number=c;
	printf("请输入你要存入的货物名称\n");
	scanf("%s",&it[c].name);
	printf("输入数量\n");
	scanf("%d",&it[c].amount);
 } 
 
 void export()
 {
	printf("输入编号\n");
	scanf("%d",&c);
	printf("你要取出的货物名称:%s\n",it[c].name);
	printf("输入取出数量\n");
	scanf("%d",&d);
	it[c].amount-=d;
	return;
 }
