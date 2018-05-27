#include<stdio.h>
#include<math.h>
int main() {

	int  a, b, c,value;
	
		printf("ËùÓĞËØÊı£º");
	
		for (int i = 2; i < =1000; i++) {
			a = sqrt(i);
			if (i%a!= 0) {
				printf("%d\n", i);
			}
			
		}
		
		
	
	system("pause");
	return 0;
}
