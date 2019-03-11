#include <stdio.h>
#include <stdlib.h>

int prime[100]={0},count=0;

int is_prime(int n)
{
    for (int i=0;i<=count;i++) if (n==prime[i]) return 1;
    return 0;
}

int main()
{
    for (int i=2;i<=100;i++)
    {
        int temp=(int)ceil(sqrt(i));
        for (int j=temp;j>=1;j--)
        {
            if (0==i%j && i!=j) break;
            if (2==j || i==j)
            {
                prime[count]=i;
                count++;
            }
        }
    }
    count--;
    for (int i=6;i<=100;i++)
    {
        int error=0;
        for (int j=i;j>=2;j--)
        {
            if (is_prime(j))
            {
                for (int k=i-j;k>=2;k--)
                {
                    if (is_prime(k))
                    {
                        int l=i-j-k;
                        if (is_prime(l))
                        {
                            printf("%d=%d+%d+%d\n",i,j,k,l);
                            j=1;k=1;error=1;
                            break;
                        }
                    }
                    if (2==k && error) printf("%d:error\n",i);
                }
            }
        }
    }
    return 0;
}
