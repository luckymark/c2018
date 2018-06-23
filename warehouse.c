#include <stdio.h>
#include <stdlib.h>

//����Ϊ4λ,����Ϊ2λ 

void print();
void outList();
void add();
void move();

int main() {
	print();
	int m;
	m=getch();
	while(1){
		system("cls");
		switch(m){
			case 49:{
				printf("����  ����\n");
				outList();
				break;
			}
			case 50:{
				add();
				break;
			}
			case 51:{
				move();
				break;
			}
			case 52:{
				printf("��лʹ��!\n");
				system("pause");
				exit(0);
				break;
			}
			default:;
		}
		system("cls");
		print();
		m=getch();
	}
	
	
	return 0;
}

void print(){
	printf("1.��ʾ����б�\n");
	printf("2.���\n");
	printf("3.����\n");
	printf("4.�˳�����\n");
}

void outList(){
	FILE *fin;
	if((fin=fopen("list.dat","r"))==NULL){
		printf("��ȡ����б�ʧ��!\n");
		system("pause");
		system("cls");
		return;
	}
	rewind(fin);
	while(!feof(fin)){
		putchar(getc(fin));
	}
	putchar(10);
	fclose(fin);
	
	system("pause");
	system("cls");
}

void add(){
	FILE *fout;
	if((fout=fopen("list.dat","a+"))==NULL){
		printf("���ļ�ʧ��!");
		system("pause");
		system("cls");
		return;
	}
	char ch='y';
	while(ch=='y'){
		char goods[20];
		int i = 0;
		printf("����������ͺ�(�� # ����):\n");
		goods[0] = getchar();
		
		while (goods[i] != '#'){
			fprintf(fout,"%c",goods[i]);
			i++;
			goods[i] = getchar();	
		}
		fprintf(fout," : ");
		
		int num;
		printf("�������������:\n");
		getchar();
		scanf("%d",&num);
		getchar();
		if(num<10){
			fprintf(fout,"%d",0);
			fprintf(fout,"%d\n",num);
		}
		else{
			fprintf(fout,"%d\n",num);
		}
		
		printf("�Ƿ����?(y/n)\n");
		ch = getch();
	}
	fclose(fout);	
}

void move(){
	FILE *fout;
	if((fout=fopen("list.dat","r+"))==NULL){
		printf("���ļ�ʧ��!");
		system("pause");
		system("cls");
		return;
	}
	
	int goods=0,num1=0,num2=0,num3=0;
	char ch='y';
	while(ch=='y'){
		long tag=7;
		printf("���������:\n");
		scanf("%d",&goods);
		getchar();
		tag=tag+1+(goods-1)*10;
		fseek(fout,tag,SEEK_SET);
		
		printf("�������������:\n");
		scanf("%d",&num1);
		getchar();
		fscanf(fout,"%d\n",&num2);
		rewind(fout);
		fseek(fout,tag,SEEK_SET);
		num3=num2-num1;
		if(num3<10){
			if(num3>0){
				fprintf(fout,"%d",0);
				fprintf(fout,"%d",num3);
			}
			else{
				printf("�����������ڿ������,����������!\n");
				continue;
			}
		}
		else{
			fprintf(fout,"%d",num3);
		}
		
		fseek(fout,tag,SEEK_SET);
		printf("�����ɹ�!�˻���Ŀǰ����:");
		fscanf(fout,"%d\n",&num2);
		printf("%d\n",num2);
		
		printf("�Ƿ����?(y/n)\n");
		ch=getch();
	}
	fclose(fout);
}

