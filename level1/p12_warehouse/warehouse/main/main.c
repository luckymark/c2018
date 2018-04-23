#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 51

FILE *fp;
int judge_vary;

int menu(void);
void show_house(void);
void add(void);
void out(void);
FILE search_location(FILE *file,int length,char *name);

int main(int argc, char *argv[]) 
{
	int menu_choose=-1;
	while(menu_choose)
	{
		menu_choose=menu();
		switch(menu_choose)
		{
			case 0:return 0;
			case 1:show_house();break;
			case 2:add();break;
			case 3:out();break;
		}
	}
	return 0;
}

int menu(void)
{
	system("cls");
	int menu_choose=-1;
	printf("�������ּ�ѡ���ܣ�\n1--��ʾ����˵�\n2--���\n3--����\n0--�˳�����\n");
	while(!( menu_choose>='0' && menu_choose<='3' ))
	{
		menu_choose=getch();
	}
	system("cls");
	return menu_choose-48;
}

void show_house(void)
{
	int ready_to_show=-1;
	fp = fopen("house.txt", "r");
	printf("    ����    ��Ʒ\n");
	while(1)
	{
		ready_to_show=getc(fp);
		if(ready_to_show==EOF)
		{
			break;
		}
		printf("%c",ready_to_show);
	}
	printf("��ʾ������");
	system("pause");     //������������������� 
	fclose(fp);
}

void add(void)                 //�����⣬�޷�������� 
{
	int add_num=1,count_add,length_of_name,before_num;
	char add_name[MAX_LENGTH]={};
	while(add_num>0)
	{
		fp = fopen("house.txt", "r+");
		fseek(fp,0L,0);
		system("cls");
		strcpy(add_name,"");
		printf("��������Ҫ��ӵĴ�����������������ӣ�����0���С��ֵ��");
		scanf("%d",&add_num);
		getchar();
		judge_vary=1;
		if(add_num<=0)
		{
			break;
		}
		printf("��������Ҫ��ӵĴ������(����ĸ��д)��");
		for(count_add=0;;count_add++)
		{
			if(count_add==50)
			{
				add_name[count_add]='\0';
				MessageBox(NULL,"�������������ϵͳ��ֻ����ǰ50���ַ�","Warning!",MB_OK);
				char ch;while((ch = getchar()) != '\n' && ch != EOF);      //��ջ����� 
				break;
			}
			add_name[count_add]=getchar();
			if(add_name[count_add]=='\n')
			{
				add_name[count_add]='\0';
				break;
			}
		}
		length_of_name=strlen(add_name);
		*fp=search_location(fp,length_of_name,add_name);    //���ص�fpָ����һ�п�ʼ�ĵط� ����δ������Ϊ��β
		if(judge_vary)      
		{
			fseek(fp,0L,2);
			if(add_num>100000)
			{
				MessageBox(NULL,"����������ݴ���10w���޷����棬ϵͳ��ֻ����100000","Warning!",MB_OK);
				add_num=100000;
			}
			fprintf(fp,"%8d    %s\n",add_num,add_name);
		}
		else
		{
			fseek(fp,-3L,1);
			fscanf(fp,"%d",&before_num);     
			add_num += before_num;
			if(add_num>100000)
			{
				MessageBox(NULL,"����������ݺ�ԭ������Ӵ���10w���޷����棬ϵͳ��ֻ����100000","Warning!",MB_OK);
				add_num=100000;
			}
			fseek(fp,-8L,1);
			fprintf(fp,"%8d    %s\n",add_num,add_name);
		}
		//�������
		fclose(fp); 
		printf("����ɹ�!\n");
		Sleep(1000);
	}
}

void out(void)
{
	int out_num=1,count_out,length_of_name,before_num;
	char out_name[MAX_LENGTH]={};
	while(out_num>0)
	{
		fp = fopen("house.txt", "r+");
		fseek(fp,0L,0);
		system("cls");
		strcpy(out_name,"");
		printf("��������Ҫɾ���Ĵ���������������ɾ��������0���С��ֵ��");
		scanf("%d",&out_num);
		getchar();
		if(out_num<=0)
		{
			return;
		}
		judge_vary=1;
		printf("��������Ҫɾ���Ĵ������(����ĸ��д)��");
		for(count_out=0;;count_out++)
		{
			if(count_out==50)
			{
				out_name[count_out]='\0';
				MessageBox(NULL,"�������������ϵͳ��ֻ����ǰ50���ַ�","Warning!",MB_OK);
				char ch;while((ch = getchar()) != '\n' && ch != EOF);      //��ջ����� 
				break;
			}
			out_name[count_out]=getchar();
			if(out_name[count_out]=='\n')
			{
				out_name[count_out]='\0';
				break;
			}
		}
		length_of_name=strlen(out_name);
		*fp=search_location(fp,length_of_name,out_name); 
		if(judge_vary)
		{
			MessageBox(NULL,"��������ڣ�����������","ERROR!",MB_OK);
			continue;
		}
		else
		{
			fseek(fp,-3L,1);
			fscanf(fp,"%d",&before_num);     
			out_num = before_num - out_num;
			if(out_num<=0)
			{
				MessageBox(NULL,"����������ݲ�С��ԭ���ݣ�ϵͳ����մ˴��","Warning!",MB_OK);
				fprintf(fp,"                                                                 ");   //Լ65���ո� 
				fclose(fp);
				printf("����ɹ���\n");
				Sleep(1000);
				continue;
			}
			fseek(fp,-8L,1);
			fprintf(fp,"%8d    %s\n",out_num,out_name);
			fclose(fp);
			printf("����ɹ���\n");
			Sleep(1000);
			continue;
		}
	}
	
}

FILE search_location(FILE *file,int length,char *name)
{
	fseek(file,1L,0);
	char wait_to_match[MAX_LENGTH]={};
	int count_match,judge_match,judge_end,match_action;
	//���м�⣬һ����⵽��ͬ�ַ���Ƕѭ�� 
	while(!fseek(file,11L,1))
	{
		strcpy(wait_to_match,"\0");
		judge_match=0;
		for(count_match=0;;count_match++)
		{
			wait_to_match[count_match]=getc(file);
			if(wait_to_match[count_match]=='\n')
			{
				wait_to_match[count_match]='\0';
				match_action=count_match;
				if(!strcmp(name,wait_to_match))
				{
					judge_match=1;
				}
				
				break;
			}
		}
		if(judge_match)
		{
			for(;count_match>0;count_match--)
			{
				fseek(file,-1L,1);
			}
			judge_vary=0;
			fseek(file,-8L,1);
			return *file;
		}
		if(getc(file)==EOF)
		{	
			break;
		}
	}
	return *file;
}
