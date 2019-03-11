//加密函数与解密函数
#include <stdio.h>
int lock(char n[],int i) {
	if (n[i]!='\0') {
		n[i]++;
		i++;
		lock(n,i);
	}
	return 1;
}
int unlock(char n[],int i) {
	if (n[i]!='\0') {
		n[i]--;
		i++;
		unlock(n,i);
	}
	return 1;
}
int main() {
	int i=0;
	char n[100];
	scanf("%s",n);
	lock(n,i);
	printf("加密后\n%s\n",n);
	i=0;
	scanf("%s",n);
	unlock(n,i);
	printf("解密后%s\n",n);
}
