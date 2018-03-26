#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000005

char Original_string[MAXN];
char After_handling[MAXN];

char encrypt(char c,int pos)
{
    return(c+(pos+1)*(pos+2));
}

char decrypt(char c,int pos)
{
    return(c-(pos+1)*(pos+2));
}



int main()
{
    scanf("%s",Original_string);
    int len=strlen(Original_string);

    printf("After encrypt:");
    int i;
    for (i=0;i<len;i++)
    {
        printf("%c",encrypt(Original_string[i],i));
    }

    printf("\nAfter decrypt:");
    for (i=0;i<len;i++)
    {
        printf("%c",decrypt(Original_string[i],i));
    }
    return 0;
}
