#include <stdio.h>
int main(void)
{
  int num,a,b,c;
  for(num=100;num<1000;num++)
  {
    a=num%10;
    b=((num-a)/10)%10;
    c=((num-10*b-a)/100);
    {
      if(num==a*a*a+b*b*b+c*c*c)   
      printf("%d\n",num);
    }
  }
  getchar();
  return 0;
}
