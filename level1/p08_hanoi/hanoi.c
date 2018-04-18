#include<stdio.h>

void hanoi(int num,char start,char end,char temp);
void put(char a,char b);

int main(void){
	int numOfdisk=0;
	scanf("%d",&numOfdisk);
	
	const char s = 'A', e = 'B' ,t = 'C';
	hanoi(numOfdisk,s,e,t);
	
	return 0;
}

void hanoi(int num,char start,char end,char temp){
	if(num == 1){
		put(start,end);
	}
	else{
		hanoi(num-1,start,temp,end);
		put(start,end);
		hanoi(num-1,temp,end,start);
	}
}

void put(char a,char b){
	printf("Move %c to %c\n",a,b);
}
