#include <stdio.h> 
#include <stdlib.h>
#define WIDE 100
 int main()
 {
	 	void delay(void);
	 	void move_right(void);
	 	void move_left(void);
	 	while (1) {
		 		move_right();
		 		move_left();
		
	}
	 	return 0;
	 }
 void delay(void)
 {
	 	int b, c;
	 	for (b = 0; b<10000; b++)
		 	for (c = 0; c<1000; c++);
	 }
 void move_right(void)
 {
	 	int i, a;
	 	for (i = 1; i <= WIDE; i++) {
		 		for (a = 0; a <= i - 1; a++)
			 		printf(" ");
		 		printf("a");
		 		delay();
		 		system("cls");
		
	}
	 }
 void move_left(void)
 {
	 	int i, a;
	 	for (i = WIDE; i >= 1; i--) {
		 		for (a = 0; a <= i - 1; a++)
			 		printf(" ");
		 		printf("a");
		 		delay();
		 		system("cls");
		
	}
	 }
