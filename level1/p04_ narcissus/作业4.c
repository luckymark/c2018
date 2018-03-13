#include<stdio.h>

int main() {

	int  a, b, c,value;
	
		printf("水仙花的数目为：");
	
		for (int i = 100; i < 1000; i++) {
			a = i % 10;/*个位*/
			b = i / 10 % 10;/*十位*/
			c = i / 100;/*百位*/
			if (c * 100 + b * 10 + a == a*a*a + b*b*b + c*c*c) {
				printf("%d\n", i);
			}
			
		}
		
		
	
	system("pause");
	return 0;
}
