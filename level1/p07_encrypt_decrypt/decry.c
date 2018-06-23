#include<stdio.h>
#include<stdlib.h>
int key;
int main(){
	printf("Please input the key:");
	scanf("%d",&key);
	printf("Please input the decry string:");
	printf("The decoded string is:");
	char c;
	getchar();
	while ((c=getchar())!='\n')printf("%c",c-key);
	printf("\n");
	return 0;
}
