#include <stdio.h>

int key,mode;
char c;
int main()
{
	printf("Please input 1 if you want to encode a string or input 2 if you want to decode a string.\n");
	scanf("%d", &mode);
	while(mode!=1 && mode!=2)
	{
		printf("ERROR!\n");
		scanf("%d",&mode);
	}
	printf("Please input the key:");
	scanf("%d", &key);
	if(mode==1)
	{
		getchar();
		printf("The encoded string is ");
		while((c=getchar())!='\n')
		{
			printf("%c",c+key);
		}	 
		
	}
	if(mode==2)
	{
		getchar();
        printf("The decoded string is ");
		while((c=getchar())!='\n')
		{
			printf("%c",c-key);
		}	 
	}
}
