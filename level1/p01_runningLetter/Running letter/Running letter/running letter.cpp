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
		11 		move_left();
		12
	}
	 	return 0;
	 }
 void delay(void)
 {
	 	int b, c;
	 	for (b = 0; b<10000; b++)
		19 	for (c = 0; c<1000; c++);
	 }
21 void move_right(void)
22 {
	23 	int i, a;
	24 	for (i = 1; i <= WIDE; i++) {
		25 		for (a = 0; a <= i - 1; a++)
			26 		printf(" ");
		27 		printf("a");
		28 		delay();
		29 		system("cls");
		30
	}
	31 }
32 void move_left(void)
33 {
	34 	int i, a;
	35 	for (i = WIDE; i >= 1; i--) {
		36 		for (a = 0; a <= i - 1; a++)
			37 		printf(" ");
		38 		printf("a");
		39 		delay();
		40 		system("cls");
		41
	}
	42 }
