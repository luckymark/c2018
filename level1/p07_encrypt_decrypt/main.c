#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
    FILE *fin,*fout;
    *fin=("E/C/in.txt",)
    */
    char a[7];
    char c;
    scanf("%s",a);
    if (strcmpi(a,"encrypt")==0)
    {
        while(c=getch()) printf("%c",c+1);
    }
    if (strcmpi(a,"decrypt")==0)
    {
        while(c=getch()) printf("%c",c-1);
    }
    return 0;
}
