#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	const char code[10]="abcabc";
     char Enter_code[10];
     printf("���������룺\n");
     scanf("%s",Enter_code);
     int count=1;
   while((strcmp(code,Enter_code))!=0 and count<=5){ 
   printf("����������벻��ȷ��������β��Խ��޷��������롣��������һ��:\n") ;
   scanf("%s",Enter_code);
   count++;
   }
    if (strcmp(code,Enter_code)==0) printf("������ȷ!\n");
   char ch,CODE[10];
   int i,a;
   printf("������Ĵ����Ѿ����꣬�밴��Ӧ��ѡ�����²���:\n");
   printf("\tA�һ�����\n\tB�˳�����\n");
   char c;
   c=getchar();
	if(c=='a'||c=='A'){
		printf("������...\n");
   for (i=0;code[i]!='\0';i++){
   		for(ch='a';ch<='z';ch++){
   			if(ch==code[i]) 
			   CODE [i]=ch;
		   }
	}
   printf("������Ϊ��\n");
   for(a=0;a<=i;a++)
   		printf("%c",CODE[a]);   
   	}
   	else if(c=='b'||c=='B') printf("�����˳����򡣡���");
	return 0;
}

