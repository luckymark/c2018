#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define n 10

char xing[100];
int num[100];
void caidan(void);

 
typedef struct xinxi
{
	char xinghao;
	int number;
	int bianhao;
	struct xinxi *next;
}xinxi,*XINXI;

XINXI p;



XINXI list(XINXI p)
{	
	XINXI q;
	XINXI head;
	head=p=(XINXI)malloc(sizeof(xinxi));
	for(int i=0;i<n;i++)
	{
		q=(XINXI)malloc(sizeof(xinxi));
		p->next=q;
		p->bianhao=i+1;
		p->number=num[i];
		p->xinghao=xing[i];
		p=p->next;
	}
	p->next=NULL;
	return head;
}

void current(XINXI p)
{
	char ss=' ';
	FILE *fp=fopen("information.txt","r");
	int m,k;
	m=1;
	XINXI elem=list(p);
	while(m!=0)
	{
		printf("请输入要入库的货物编号以及数量(输入0 0停止入库)\n");
		scanf("%d %d",&m,&k);
		if(m==0&&k==0)
		{
			system("cls");
			fp=fopen("information.txt","w");
			for(int i=0;i<n;i++)
			{
				fprintf(fp,"%d%c%c",num[i],xing[i],ss);
			}
			fclose(fp);		 
			caidan(); 
		}
		if(elem->bianhao==m)
		{
				elem->number=elem->number+k;
				num[m-1]=num[m-1]+k;
				printf("成功入库！剩余库存%d\n",elem->number);
				printf("按任意键继续\n");
				getch();
				system("cls");
				continue;
			
		} 
		else if(elem->bianhao!=m) 
		{
			elem=elem->next;
			while(elem!=NULL) 
			{
			
				if(elem->bianhao==m)
				{
						elem->number=elem->number+k;
						num[m-1]=num[m-1]+k;
						printf("成功入库！剩余库存%d\n",elem->number);
						printf("按任意键继续\n");
						getch();
						system("cls");
						break;
				}
			}
		}
			fp=fopen("information.txt","w");
			for(int i=0;i<n;i++)
			{
				fprintf(fp,"%d%c%c",num[i],xing[i],ss);
			}
			fclose(fp);		  
	}

			

}


void output(XINXI p)
{
	char ss=' ';
	FILE *fp=fopen("information.txt","r");
	int m,k;
	m=1;
	XINXI elem=list(p);
	while(m!=0)
	{
		printf("请输入要出库的货物编号以及数量(输入0 0停止出库)\n");
		scanf("%d %d",&m,&k);
		if(m==0&&k==0)
	{
		system("cls");
			fp=fopen("information.txt","w");
			for(int i=0;i<n;i++)
			{
				fprintf(fp,"%d%c%c",num[i],xing[i],ss);
			}
			fclose(fp);		 
		caidan(); 
	}
		if(elem->bianhao==m)
		{
			if(elem->number-k>=0)
			{
				elem->number=elem->number-k;
				num[m-1]=num[m-1]-k;
				printf("成功出库！剩余库存%d\n",elem->number);
				printf("按任意键继续\n");
				getch();
				system("cls");
				continue;
			}
			else
			{
				printf("库存不足！出库失败！\n");
				printf("按任意键继续\n");
				getch();
				system("cls");
				continue;
			}
			
		}
		else
		{
			while(elem!=NULL) 
			{
				elem=elem->next;
				if(elem->bianhao==m)
				{
					if(elem->number-k>=0)
					{
						elem->number=elem->number-k;
						num[m-1]=num[m-1]-k;
						printf("成功出库！剩余库存%d\n",elem->number);
						printf("按任意键继续\n");
						getch();
						system("cls");
						break;
					}
					else
					{
						printf("库存不足！出库失败！\n");
						printf("按任意键继续\n");
						getch();
						system("cls");
						break;
					}
				}
			}
		}
		fp=fopen("information.txt","w");
			for(int i=0;i<n;i++)
			{
				fprintf(fp,"%d%c%c",num[i],xing[i],ss);
			}
			fclose(fp);		 
	}
}

















void caidan()
{
	printf("#####################################\n");
	printf("###########欢迎使用销存功能##########\n");
	printf("######                     #########\n");
	printf("########    按键说明如下   ##########\n");
	printf("#######  2 ->显示存货列表  ###########\n");
	printf("#######  3 ->入库          ###########\n");
	printf("#######  4 ->出库          ###########\n");
	printf("#######  5 ->退出程序 并保存库存信息 #####\n");
	char ch;
	char gh;
	char c[100];
	char ss=' ';
	int k=0;
	FILE *fp=fopen("information.txt","r");
	FILE *fpRead=fopen("information.txt","r");
	if(fpRead!=NULL)
	{
		for(int i=0;i<1000;i++)
		{
			fscanf(fpRead,"%d%c",&num[i],&xing[i]);
		}
	}
	ch=getch();
	switch(ch)
	{
		case '2':
			system("cls");
			
			while(fscanf(fp,"%c",&c[k])!=EOF)
			{
				printf("%c",c[k]);
				k++;
			}
				
    		printf("\n");
			printf("按5返回至主界面\n");

			gh=getch();
			if(gh==5);
			{
				system("cls");
				caidan();
			}
		break;
		case '3':
			current(p);
			printf("\n");
			printf("按5返回至主界面\n");
			gh=getch();
			if(gh==5);
			{
				system("cls");
				caidan();
			}
			
		break;
		case '4':
			output(p);
			printf("\n");
			printf("按5返回至主界面\n");
			gh=getch();
			if(gh==5);
			{
				system("cls");
				caidan();
			}

		break;
		case '5':
			fp=fopen("information.txt","w");
			for(int i=0;i<n;i++)
			{
				fprintf(fp,"%d%c%c",num[i],xing[i],ss);
			}
			fclose(fp);		
		break;
		default:
		printf("输入无效\n");	
	}
}
int main()
{
	caidan();
	return 0;
}
