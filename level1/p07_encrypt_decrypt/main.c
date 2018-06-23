#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*reverse encrypt*/
int main(int argc, char *argv[]) {
	char c[1000];
	fgets(c,(sizeof c / sizeof c[0]),stdin);
	int d = strlen(c);
	
	char a[1000];
	int j = 0;
	for (int i=d-2;i>=0;i--)
	{
		a[i] = c [j];
		j++;
	}
	puts(a);
	return 0;
}
