#include <stdio.h>
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
    bool prime[120]={};
    prime[1]=prime[2]=true;
    for(int num=3;num<=100;num+=2)
    {
        if(isPrime(num)){
            prime[num]=true;
        }
    }
    bool checkAll=true;
    for(int num=2;num<=100;num+=2) {
        bool checkNum = false;
        for (int i = 1; i <= num / 2; i++) {
            if (prime[i] && prime[num - i]) {
                checkNum = true;
                printf("%d = %d + %d\n",num,i,num-i);
                break;
            }
        }
        if(!checkNum){
            checkAll=false;
            break;
        }
    }
    if(checkAll){
        printf("Proved!");
    }
    else printf("Failed!");
    return 0;
}

