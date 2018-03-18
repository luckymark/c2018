#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define MAX 80
#define SPEED 5 

void print_space(int max);

 int main(void)
 {
 	int i;
 	
 	while(MAX)
 	{
	 
		for(i = 0 ; i <= MAX ; i++)
	 	{ 			
 			print_space(i);
		}
	
		for(i = MAX ; i >= 0 ; i--)
	 	{ 			
 			print_space(i);
		}
	}
	return 0;
}
 
 void print_space(int max)
 {
 	int num = 0;
 	for(num = 0; num <= max; num++)
 	{
 		printf(" ");
	}
	printf("a");
	Sleep(SPEED);
 	system("cls");
	
 }
