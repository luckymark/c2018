#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

int main()
{
	int i,j,p,key,count;
	char word[NUM],function;
	char small_letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
							'o','p','q','r','s','t','u','v','w','x','y','z'};
	char big_letter[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
						'P','Q','R','S','T','U','V','W','X','Y','Z'};
						
	count = 0;
	i = 0;
	
	printf("Please input your word:\n");
	while((word[i] = getchar()) != '\n')
	{
		i++;
		count++;
	}
	
	printf("Encrypt or Decrypt? E or D :\n");
	scanf("%c", &function);
	
	if(function == 'E')
	{
		printf("Please input your key:\n");
		scanf("%d", &key);
		for(i = 0; i < count; i++)
		{
			if(word[i] >= 'A' && word[i] <= 'Z')
			{
				p = (((word[i] - 'A') + key) % 26);
				printf("%c", big_letter[p]);
			}
			else if(word[i] >= 'a' && word[i] <= 'z')
			{
				p = (((word[i] - 'a') + key) % 26);
				printf("%c", small_letter[p]);
			}
		}
	}
	
	if(function == 'D')
	{
		printf("Please input your key:\n");
		scanf("%d", &key);
		for(i = 0; i < count; i++)
		{
			if(word[i] >= 'A' && word[i] <= 'Z')
			{
				p = (word[i] - 'A') - key;
				if(p < 0)
					p += 26;
				printf("%c", big_letter[p]);
			}
			else if(word[i] >= 'a' && word[i] <= 'z')
			{
				p = (word[i] - 'a') - key;
				if(p < 0)
					p += 26;
				printf("%c", small_letter[p]);
			}
		}
	}
	return 0;
 } 
