#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int change(n,position1,position2)
{
	//得到position3 
	char position3;
	 if(position1 == 'A')
	 {
	 	if(position2 == 'B')
		 {
		 	position3 = 'C';
		 }
	 	else
		 {
		 	position3 = 'B';
		 }
	 }
	 else if(position1 == 'B')
	 {
	 	if(position2 == 'A')
	 	{
	 		position3 = 'C';
	 	}
	 	else
	 	{
	 		position3 = 'A';
	 	}
	 }
	 else
	 {
	 	if(position2 == 'A')
	 	{
	 		position3 = 'B';
	 	}
	 	else
	 	{
	 		position3 = 'A';
	 	}
	 }
	 
	 if(n==1)
	 {
	 	printf("%c->%c\n",position1,position2);
	 	return 0;
	 } 
	 
	 change(n-1,position1,position3);
	 change(1,position1,position2);
	 change(n-1,position3,position2);	
}
int main(int argc, char *argv[]) {
	int n;
	printf("输入塔的层数\n");
	scanf("%d",&n);
	change(n,'A','B');
	return 0;
}
