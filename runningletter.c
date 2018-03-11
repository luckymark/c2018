#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define WIDE 118 
 
int main(void){
	char s[20];
	int x=0;
	int dir=1;
	int i;
	
	scanf("%s",s);
	while(1){
		system("cls");
		for(i=0;i<=x;i++){ 
			printf(" ");
		}
		Sleep(100);
		puts(s);
		x += dir;
		if(x == WIDE-1)
			dir=-1;
		else if(x==0)
			dir=1;
	}
	 
	return 0;	
} 
