#include <stdio.h>
#include <MacTypes.h>
#include <math.h>

Boolean isPrime(int num)
{
    
    int MAX=sqrt((float)(num))+1;
    if(num==1||num==2)
    {
        return true;
    }
    for(int i=2;i<=MAX;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
    
}


int main() {
    int num;
    
    while (printf("Please input a number:"),scanf("%d", &num) != EOF) {
        if (isPrime(num)) {
            printf("this number is prime!\n");
        } else {
            printf("this number is not prime\n");
        }
    }
    return 0;
}
