//Diophantus
#include <stdio.h>
int main() {
	int n=0;
	for (int i=0; i<100; i++) {
		if (i%6==0&&i%12==0&&i%7==0) {
			if (i%2==0&&(i-4-i/2-5)==(i/6+i/12+i/7)) {
				printf("丢番图失去儿子那年他%d岁",i-4);
			}
		}
	}
	return 1;
}
