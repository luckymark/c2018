#include <stdio.h>

int gcd(int x,int y)
{
    return !y?x:gcd(y,x%y);
}

int main() {
    int date[]={6,12,7,2};
    int age=1;
    for(int i=0;i<4;i++)
    {
        age=(age*date[i])/gcd(age,date[i]);
    }
    printf("the Diophantus's age is %d",age);
    return 0;
}
