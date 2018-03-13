#include <stdio.h>
#include <time.h>
#include <math.h>
#include <MacTypes.h>

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
    clock_t t1,t2;
    t1=clock();
    printf("2");
    for(int num=3;num<1000;num+=2)
    {
        if(isPrime(num)){
            printf(" %d",num);
        }
    }
    t2=clock();
    printf("\nSpend %dms",t2-t1);
    return 0;
}
