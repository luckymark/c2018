#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 50
bool encrypt(char*,char*);
bool decrypt(char*,char*);
int main(void){
	char trueForm[N];
	char secret[N];
	char a;
	printf("想要加密请输入1，解密请输入2,退出请输入0\n");
	while(1)
	{
		
		a=getchar();
		while(a!='1'&&a!='2'&&a!='0')
		{
			printf("qiudoumadei想要加密请输入1，解密请输入2,退出请输入0\n");
			a=getchar();
		} 
		while(getchar()=='/n');
		if(a=='0')
		{
			return 0;
		}
		else if(a=='1')
		{
			printf("请输入由字母（大小写均可）和数字组成的原码:\n");
			scanf("%s",trueForm);
			while(!encrypt(trueForm,secret))
			{ 
				printf("只能输入字母（大小写均可）和数字！\n");
				scanf("%s",trueForm); 
			}
			printf("对应的密码是：\n");	
			puts(secret);
		}
		else
		{
			printf("请输入密码:\n");
			scanf("%s",trueForm);
			while(!decrypt(trueForm,secret))
			{ 
				printf("只能输入字母（大小写均可）和数字！\n");
				scanf("%s",trueForm); 
			}
			printf("对应的原码是：\n");	
			puts(secret);
		}
		printf("想要加密请输入1，解密请输入2,退出请输入0\n");
		while(getchar()=='/n');
	}
	return 0;
	
}
bool encrypt(char* t,char *s){
	int twide,i;
	twide=strlen(t);
	for(i=0;i<twide;i++)
	{
		if((t[i]<'7'&&t[i]>='0')||(t[i]<120&&t[i]>96)||(t[i]<88&&t[i]>64))
			s[i]=t[i]+3;
		else if((t[i]<123&&t[i]>119)||(t[i]<91&&t[i]>87))
			s[i]=t[i]-23;
		else if(t[i]<='9'&&t[i]>'6')
			s[i]=t[i]-7;
		else
		{
			return false;
			s[twide]='\0';
		}
			
	}
	s[twide]='\0';
	return true;
} 
bool decrypt(char* s,char *y){
	int twide,i;
	twide=strlen(s);
	for(i=0;i<twide;i++)
	{
		if((s[i]<='9'&&s[i]>'2')||(s[i]<123&&s[i]>99)||(s[i]<91&&s[i]>67))
			y[i]=s[i]-3;
		else if((s[i]<100&&s[i]>96)||(s[i]<68&&s[i]>64))
			y[i]=s[i]+23;
		else if(s[i]<'3'&&s[i]>='0')
			y[i]=s[i]+7;
		else
		{
			return false;
			y[i]='\0';
		}
			
	}
	return true;
} 
