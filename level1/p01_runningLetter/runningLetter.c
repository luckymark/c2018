#include <stdio.h>
#include <stdlib.h>
#define Lenth 80 
int i,j,k,*p0=&k,*p1=&i;
void run(int *a)
{
  for(i=0;i<Lenth;i++)
  {
    k=Lenth-i;
    for(j=*a;j<Lenth;j++)
    {
      printf(" ");	
    }
    printf("hhy");
    system("cls");
  }  
}
int main(void)
{
  for(;;)
  {
    run(p0);
    run(p1);
  }
  getchar();
  return 0;
}
