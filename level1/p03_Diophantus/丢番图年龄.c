#include <stdio.h>

int main()
{
	float m,n;
	float a,b,c,d;
	
	for(m = 9;; m++)
	{
		a = m / 6;
		b = m / 12;
		c = m / 7;
		d = m / 2;
		
		n = a + b + c + 5 + d + 4;
		
		if(m == n)
			break;
	}
	
	m = m - 4;
	printf("He was %.0f years old when his son died.\n", m);
	
	return 0;
 } 
