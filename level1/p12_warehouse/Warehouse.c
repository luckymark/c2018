#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct list{
	char name[20];
	int amount;
	float price;
}list[20];
int i=0;
FILE *fp;
void displaylist(void);
void inlist(void);
void outlist(void);
void menu (void);
int main(int argc, char *argv[]) {
	menu();
	while(1){
		char c=NULL;
		c=getchar();
	switch(c){
		case '1':displaylist();break;
		case '2':inlist();break;
		case '3':outlist();break;
		case '4': exit(0);
	}  
}
	return 0;
}
void displaylist (void)
{
	int a;
	fp=fopen("list","r");
	if (fp==NULL) 
	{
		printf("�б�Ϊ��\n");
	}
	else
	{
	printf("����		����		����/Ԫ\n");
	for(a=0;fread(&list[a],sizeof(struct list),1,fp)!=0;a++)
	{
		printf("%s 	         %d		  %.2f\n",list[a].name,list[a].amount,list[a].price);
	}
	}
	fclose(fp);
	printf("\n\n");
	menu();
}
void inlist ()
{
	fclose(fp);
	char ch;
	do
	{
	FILE *f=fopen("book","w");
	fp=fopen("list","r");
	int k ,q=1;
	char namel[20];
	int amountl;
	float pricel;
	printf("�������������\n");
	scanf("%s",namel);
	printf("������û����������\n");
	scanf("%d",&amountl);
	printf("������û��ﵥ��\n");
	scanf("%f",&pricel);
	for(k=0;fread(&list[k],sizeof(struct list),1,fp)!=0;k++)
	{
		if(strcmp(namel,list[k].name)==0)
		{	 
			q=0;
			printf("�û����Ѿ����ڣ��Ƿ��޸�ԭ�����ۣ�Y��/N��\n");
			char choice;
			getchar(); /*����س���*/
			scanf("%c",&choice);
			if(choice=='y' || choice=='Y')
			{
				list[k].price=pricel;
			} 
			list[k].amount=list[k].amount+amountl; 
		}
		fwrite(&list[k],sizeof(struct list),1,f);
	}
	fclose(f);
	fclose(fp);
	f=fopen("book","r");
	fp=fopen("list","w");
	for(k=0;fread(&list[k],sizeof(struct list),1,f)!=0;k++)
	{
		fwrite(&list[k],sizeof(struct list),1,fp);
	} 
	fclose(f);
	fclose(fp);
	if (q)
	{
		fp=fopen("list","a");
		strcpy(list[i].name,namel);
		list[i].amount=amountl;
		list[i].price=pricel;
		fwrite(&list[i],sizeof(struct list),1,fp);
		fclose(fp);
	}
	i++;
	printf("�Ƿ�Ҫ������� ��Y��/N��");
	getchar();/*����س���*/
	ch=getchar(); 
	}while(ch=='y' || ch=='Y');
	printf("\n\n");
	menu();
}
void outlist(void)
{
	fp=fopen("list","r");
	FILE *fpf=fopen("book","w");
	printf("��������Ҫ�����������\n");
	char namel[20];
	scanf("%s",namel);
	printf("��������Ҫ���������\n");
	int n;
	scanf("%d",&n);
	int d;
	for(d=0;fread(&list[d],sizeof(struct list),1,fp)!=0;d++)
	{
		if(strcmp(namel,list[d].name)==0) 
		{
			if(list[d].amount-n<0)
			{
				printf("��Ʒ����!\n"); 
			}
			else
			{
			list[d].amount=list[d].amount-n;
			}
		}
		fwrite(&list[d],sizeof(struct list),1,fpf);
	}
	fclose(fpf);
	fclose(fp);
	fpf=fopen("book","r");
	fp=fopen("list","w");
	for(d=0;fread(&list[d],sizeof(struct list),1,fpf)!=0;d++)
	{
		fwrite(&list[d],sizeof(struct list),1,fp);
	} 
	fclose(fpf);
	fclose(fp);
	printf("\n\n");
	menu();
}
void menu (void)
{
	printf("�˵��� \n");
	printf("\t1.��ʾ����б�\n");
	printf("\t2.���\n");
	printf("\t3.����\n");
	printf("\t4.�˳�����\n");
}
