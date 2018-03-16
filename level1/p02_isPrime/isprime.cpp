#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
	long long n,i;
	printf("Please enter a numer for prime judging\n");
	while(scanf("%I64d",&n)!=EOF){
		bool flag=0;
		for(i=2;i<ceil(sqrt(n));i++){
			if(n%i==0){
				flag=1;
				break;
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
