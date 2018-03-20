#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int number;
	int hundred;
	int ten;
	int one;
	int target;
	
	number = 100;
	while(number<=999)
	{
		hundred = number/100;
		ten = (number-hundred*100)/10;
		one = number%10;
		target = pow(hundred,3)+pow(ten,3)+pow(one,3);
		if(target==number)
		{
			printf("%d\n",number);
		}
		number++;
	}
	return 0;
}
