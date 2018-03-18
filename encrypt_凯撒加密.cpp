#include <stdio.h>
#include <string.h>

int main(){
	int bit;
	char *text,ch,i=0;
	scanf("%d",&bit);
	getchar();
	while((ch=getchar())!=EOF){
		if(ch=='\n'){
			printf("\n");
			continue;
		}
		if(ch==' '){
			printf(" ");
			continue;
		}
		printf("%c",ch+bit);
		i++;
	}
	return 0;
} 
