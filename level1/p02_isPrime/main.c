#include <stdio.h>
#include <stdlib.h>
#define MIN_PRIME 2
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*input*/
	printf("Please input a number\n");
	int number;
	scanf("%d",&number);
	
	/*judgement*/
	int i;
	for(i=MIN_PRIME;i<number;i++){
		if(number==MIN_PRIME){
			goto is_prime;
		}
		else if(number%i!=0){		
			continue;
		}
		else{
			goto is_not_prime;
		}
	}
	
	/*print*/
is_prime:
	printf("%d is a prime.\n",number);
	return 0;
is_not_prime:
	printf("%d is not a prime.\n",number);	
	return 0;
}
