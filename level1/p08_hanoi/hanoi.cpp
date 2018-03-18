#include <stdio.h>
#define NUM 64

//move to C from A 

void move(int n,char a,char b,char c){
	if(n==1){
		printf("%c --> %c\n",a,c);
		return;
	}
	else{
		move(n-1,a,c,b);
		printf("%c --> %c\n",a,c);
		move(n-1,b,a,c);
	}
} 


int main(){
	int n;
	n=NUM;
	move(n,'A','B','C');
} 
