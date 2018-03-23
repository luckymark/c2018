#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	const char code[10]="abcabc";
     char Enter_code[10];
     printf("请输入密码：\n");
     scanf("%s",Enter_code);
     int count=1;
   while((strcmp(code,Enter_code))!=0 and count<=5){ 
   printf("你输入的密码不正确，输入五次不对将无法继续输入。请再输入一遍:\n") ;
   scanf("%s",Enter_code);
   count++;
   }
    if (strcmp(code,Enter_code)==0) printf("密码正确!\n");
   char ch,CODE[10];
   int i,a;
   printf("您输入的次数已经用完，请按对应键选择以下操作:\n");
   printf("\tA找回密码\n\tB退出程序\n");
   char c;
   c=getchar();
	if(c=='a'||c=='A'){
		printf("解密中...\n");
   for (i=0;code[i]!='\0';i++){
   		for(ch='a';ch<='z';ch++){
   			if(ch==code[i]) 
			   CODE [i]=ch;
		   }
	}
   printf("该密码为：\n");
   for(a=0;a<=i;a++)
   		printf("%c",CODE[a]);   
   	}
   	else if(c=='b'||c=='B') printf("正在退出程序。。。");
	return 0;
}

