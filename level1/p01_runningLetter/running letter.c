#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#define WIDTH 60
#define SPEED 25  //数值越小越快 
int main(){
	system("mode con cols=60 lines=20");  //改变控制台窗口尺寸 
	//上方语句若将60改为WIDTH会出错，不知道如何解决 
	int i,j,n;
	char A[WIDTH] ;
	gets(A);
	n=strlen(A);
	int blank=WIDTH-n;   //空白处总长blank不变 
	while(1){
		for(i=0;i<2*blank;i++){
			if(i<blank){
				for(j=0;j<i;j++){
					printf(" ");
				}
			}
			else{
				for(j=blank;j>i-blank;j--){
					printf(" ");
				}
			}
			for(j=0;j<n;j++){
				printf("%c",A[j]);
			}
			Sleep(SPEED);
			system("cls");
	}
	}
} 
