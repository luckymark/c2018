#include <stdio.h>
#include <stdlib.h>
int amount,c,d,e;
int judge=0;
struct item
{
	int action;
	char name[100];
	int amount;
}ware[10000];

void begin();
void menu(); 
void display();

int main(int argc, char *argv[]) 
{
	//begin();
	while(1)
	{
		menu();
		if(1==judge)break;
	} 
	printf("see you!\n") ;
	return 0;
}

void menu()
{
	beginning:system("cls");
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



void begin()
{
	FILE *fp=fopen("warehouse.txt","rb");
	if(fp == NULL)
    return -1;
    while(!feof(fp))
    {
    	fscanf("%d",&e);
    	fscanf("%s%d",ware[e].name,&ware[e].amount);
	}
	fclose(fp);
}

void display()
{
	char ch;
	system("cls");
	FILE *fp;
	fp=fopen("warehouse.txt","w");
	int i=1;
	for(i=1;i<10000;i++)
	{
		if(ware[i].action==1)
		fprintf(fp,"%d %s %d\n",i,ware[i].name,ware[i].amount);
	}
	fp=fopen("warehouse.txt","r");
	ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    printf("\n");
	fclose(fp);
	printf("按任意键返回菜单\n");
	ch=getchar();
}
void import()
{
	printf("输入编号\n");
	scanf("%d",&c);
	//ware[c].number=c;
	ware[c].action=1;
	printf("请输入你要存入的货物名称\n");
	scanf("%s",&ware[c].name);
	printf("输入数量\n");
	scanf("%d",&ware[c].amount);
 } 
 
 void export()
 {
	printf("输入编号\n");
	scanf("%d",&c);
	printf("你要取出的货物名称:%s\n",ware[c].name);
	printf("输入取出数量\n");
	scanf("%d",&d);
	ware[c].amount-=d;
	return;
 }
