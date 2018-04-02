#include<stdio.h> 

#include<stdlib.h>

#include <windows.h>

int main()

{

	char c[100];

	gets(c);

	while(1)

    {

	  for(int i=1;i<=115;i++)

	  {

	    for(int j=1;j<i;j++)

	    printf(" ");

	    printf("%s",c);

	    Sleep(20);

	    system("CLS");

	  }

	  for(int k=114;k>=1;k--) 

	  {

	  	for(int j=1;j<=k;j++)

	  	printf(" ");

	  	printf("%s",c);

	  	Sleep(20);

	    system("CLS");

	  }

	}

	return 0;

}
