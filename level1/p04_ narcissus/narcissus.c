#include<stdio.h>
#include<math.h>
#define MAX 1000
#define MIN 100
#define third(c) pow(c,3) 
int main(void){
	int i;
	int a,x,y,z;
	
	for(i=100;i<1000;i++){
		a=i/10;
		z=i%10;
		y=a%10;
		x=i/100;
		int t=third(x)+third(y)+third(z);
		
		if(i == t )
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
