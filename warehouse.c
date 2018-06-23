#include <stdio.h>
#include <stdlib.h>

//货号为4位,数量为2位 

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
				printf("货号  数量\n");
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
				printf("感谢使用!\n");
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
	printf("1.显示存货列表\n");
	printf("2.入库\n");
	printf("3.出库\n");
	printf("4.退出程序\n");
}

void outList(){
	FILE *fin;
	if((fin=fopen("list.dat","r"))==NULL){
		printf("读取存货列表失败!\n");
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
		printf("打开文件失败!");
		system("pause");
		system("cls");
		return;
	}
	char ch='y';
	while(ch=='y'){
		char goods[20];
		int i = 0;
		printf("请输入货物型号(以 # 结束):\n");
		goods[0] = getchar();
		
		while (goods[i] != '#'){
			fprintf(fout,"%c",goods[i]);
			i++;
			goods[i] = getchar();	
		}
		fprintf(fout," : ");
		
		int num;
		printf("请输入货物数量:\n");
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
		
		printf("是否继续?(y/n)\n");
		ch = getch();
	}
	fclose(fout);	
}

void move(){
	FILE *fout;
	if((fout=fopen("list.dat","r+"))==NULL){
		printf("打开文件失败!");
		system("pause");
		system("cls");
		return;
	}
	
	int goods=0,num1=0,num2=0,num3=0;
	char ch='y';
	while(ch=='y'){
		long tag=7;
		printf("请输入货号:\n");
		scanf("%d",&goods);
		getchar();
		tag=tag+1+(goods-1)*10;
		fseek(fout,tag,SEEK_SET);
		
		printf("请输入出库数量:\n");
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
				printf("出库数量大于库存数量,请重新输入!\n");
				continue;
			}
		}
		else{
			fprintf(fout,"%d",num3);
		}
		
		fseek(fout,tag,SEEK_SET);
		printf("操作成功!此货物目前数量:");
		fscanf(fout,"%d\n",&num2);
		printf("%d\n",num2);
		
		printf("是否继续?(y/n)\n");
		ch=getch();
	}
	fclose(fout);
}

