#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define MAX 80

void print_space(int max);

 int main(void)
 {
 	int i;
 	
	for(i = 0 ; i <= MAX ; i++)
 	{ 			
 		print_space(i);
 		printf("a");
 		
 		Sleep(10);
 		system("cls");
	}
	
	for(i = MAX ; i >= 0 ; i--)
 	{ 			
 		print_space(i);
 		printf("a");
 		
 		Sleep(10);
 		system("cls");
	}
	return 0;
}
 
 void print_space(int max)
 {
 	int num = 0;
 	for(num = 0; num <= max; num++)
 			printf(" ");
 }
