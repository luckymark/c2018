#include <stdio.h>
#include <MacTypes.h>


int myCube(int num)
{
    return num*num*num;
}

Boolean check(int num)
{
    int onesPlace,tensPlace,hundredsPlace;
    onesPlace=num%10;
    tensPlace=num%100/10;
    hundredsPlace=num/100;
    return myCube(onesPlace)+myCube(tensPlace)+myCube(hundredsPlace)==num?true:false;
}


int main() {
    for(int i=100;i<=999;i++)
    {
        if(check(i)){
            printf("%d ",i);
        }
    }
    return 0;
}
