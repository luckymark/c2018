#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define n 10

char variety[100];
int num[100];

void menu(void);

typedef struct information {
	char type;             //型号
	int number;            //编号
	int amount;            //数量
	struct information *next;
} information,*INFORM;

INFORM p;

INFORM list(INFORM p) {
	INFORM q;
	INFORM head;
	head=p=(INFORM)malloc(sizeof(information));      //为头链表分配内存
	for(int i=0; i<n; i++) {
		q=(INFORM)malloc(sizeof(information));
		p->next=q;
		p->number=i+1;
		p->amount=num[i];
		p->type=variety[i];
		p=p->next;
	}
	p->next=NULL;
	return head;
}

void input(INFORM p) {                        //货物入库
	char a=' ';
	FILE *fp=fopen("information.txt","r");     //打开外部文件
	int b,c;
	b=1;
	INFORM element=list(p);
	while(b!=0) {
		printf("请输入需入库货物的编号及数量（输入0 0停止输入）");
		scanf("%d %d",&b,&c);
		if(b==0&&c==0) {
			system("cls");
			fp=fopen("information.txt","w");
			for(int i=0; i<n; i++) {
				fprintf(fp,"%d%c%c",num[i],variety[i],a);
			}
			fclose(fp);
			menu();

		}
		if(element->number==b) {
			element->amount=element->amount+c;      //在amount后c个位置插入货物
			num[b-1]=num[b-1]+c;
			printf("入库成功！剩余库存%d\n",element->number);
			printf("按任意键继续\n");
			getch();
			system("cls");
			continue;
		} else if(element->number!=b) {
			element=element->next;
			while(element!=NULL) {
				if(element->number==b) {
					element->amount=element->amount+c;
					num[b-1]=num[b-1]+c;    //在amount后c个位置插入货物
					printf("入库成功！剩余库存%d\n",element->number);
					printf("按任意键继续\n");
					getch();
					system("cls");
					break;
				}
			}
		}
		fp=fopen("information.txt","w");
		for(int i=0; i<n; i++) {
			fprintf(fp,"%d%c%c",num[i],variety[i],a);
		}
		fclose(fp);
	}

}

void output(INFORM P) {
	char a=' ';
	FILE *fp=fopen("information.txt","r");     //打开外部文件
	int b,c;
	b=1;
	INFORM element=list(p);
	while(b!=0) {
		printf("请输入需出库货物的编号及数量（输入0 0停止输入）");
		scanf("%d %d",&b,&c);
		if(b==0&&c==0) {
			system("cls");
			fp=fopen("information.txt","w");
			for(int i=0; i<n; i++) {
				fprintf(fp,"%d%c%c",num[i],variety[i],a);
			}
			fclose(fp);
			menu();

		}
		if(element->number==b) {
			if(element->amount-c>=0) {
				element->amount=element->amount+c;      //在amount后c个位置取出货物
				num[b-1]=num[b-1]+c;
				printf("入库成功！剩余库存%d\n",element->number);
				printf("按任意键继续\n");
				getch();
				system("cls");
				continue;
			} else {
				printf("库存不足！出库失败！\n");
				printf("按任意键继续\n");
				getch();
				system("cls");
				continue;

			}
		} else 
		 {
			while(element!=NULL)
			 {
			   element=element->next;
			   if(element->number==b)
			   {
			   	if(element-c>=0)
			   	{
			   			
					element->amount=element->amount-c;
					num[b-1]=num[b-1]-c;    //在amount后c个位置插入货物
					printf("出库成功！剩余库存%d\n",element->number);
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
		for(int i=0; i<n; i++) {
			fprintf(fp,"%d%c%c",num[i],variety[i],a);
		}
		fclose(fp);
	}

}

void menu()
{
	printf("                                   \n");
	printf("           仓库管理系统            \n");
	printf("                                   \n");
	printf("           显示货存列表请按 2      \n");
	printf("           入库请按 3              \n");
	printf("           出库请按 4              \n");
	printf("           保存并退出程序请按 5    \n");
	char ch;
	char gh;
	char d[100];
	char a=' ';
	int c=0;
	FILE *fp=fopen("information.txt","r");
	FILE *fpRead=fopen("information.txt","r");
	if(fpRead!=NULL)
	{
		for(int i=0;i<1000;i++)
		{
			fscanf(fpRead,"%d%c",&num[i],&variety[i]);
			
		}
	}
	ch=getch();
	switch(ch)
	{
		case '2':
		system("cls");
		while(fscanf(fp,"%c",&d[c])!=EOF)
		{
			printf("%c",d[c]);
			c++;
		}
	
	printf("\n");
	printf("按5返回至主界\n");
	gh=getch();
	if(gh==5)
	{
		system("cls");
		menu();
	}
	break;
	
	case '3':
		input(p);
		printf("\n");
		printf("按5返回至主界\n");
		gh=getch();
		if(gh==5)
		{
			system("cls");
			menu();
		 } 
		 break;
		 
	case '4':
    	output(p);
		printf("\n");
		printf("按5返回至主界\n");
	    gh=getch();
	    if(gh==5)
	   	{
			system("cls");
			menu();
		    } 
		  break;
		  
		  case '5':
		  	fp=fopen("information.txt","w");
		  	for(int i=0;i<n;i++)
		  	{
		  		fprintf(fp,"%d%c%c",num[i],variety[i],a);
		  		
			  }
			  fclose(fp);
			  break;
			  default:
			  	printf("输入无效，请输入指定数字\n");
			  	
		 	
	}
}
int main()
{
	menu();
	return 0;
}
	


