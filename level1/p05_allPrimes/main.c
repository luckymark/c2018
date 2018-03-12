//素数筛选法，LENGTH定义为不同值时输出值以内的所有素数
//time函数适用于linux,time1为不包括printf的时间，time2为总时间

/*某超低配cpu在LENGTH=1000时的output:
 * 168 prime numbers found.
Generating time: 13us=0.000013s
Total time: 1205us=0.001205s*/

/*LENGTH=1000000:
78498 prime numbers found.
Generating time: 21312us=0.021312s
Total time: 1377381us=1.377381s*/

/*LENGTH=10000000:
 * 664579 prime numbers found.
Generating time: 330071us=0.330071s
Total time: 12239835us=12.239835s*/


#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#define LENGTH 1000

char NotPrime[LENGTH] = {0};

long isPrime(long number) {
    for (long i = 2; i < number; i++) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void GetPrimes() {
    long i = 1;
    while ((i + 1) < sqrt(LENGTH)) {
        if (!NotPrime[i]) {
            if (isPrime(i + 1)) {
                for (int j = 2 * (i + 1); j < LENGTH; j += (i + 1))
                    NotPrime[j - 1] = 1;
            } else {
                NotPrime[i] = 1;
            }
        }
        i++;
    }

}

int main() {
    struct timeval start, end1, end2;

    gettimeofday(&start, NULL);
    GetPrimes();
    gettimeofday(&end1, NULL);

    int count = 0;
    for (int i = 1; i < LENGTH - 1; i++) {
        if (!NotPrime[i]) {
            count++;
            printf("%d\n", i + 1);
        }
    }

    gettimeofday(&end2, NULL);

    int timeuse1 = 1000000 * (end1.tv_sec - start.tv_sec) + end1.tv_usec - start.tv_usec;
    int timeuse2 = 1000000 * (end2.tv_sec - start.tv_sec) + end2.tv_usec - start.tv_usec;

    printf("\n%d prime numbers found.\nGenerating time: %dus=%fs\nTotal time: %dus=%fs", count,
           timeuse1, ((float) timeuse1 / 1000000),
           timeuse2, ((float) timeuse2 / 1000000));
    return 0;
}