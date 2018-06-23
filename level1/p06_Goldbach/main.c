#include <stdio.h>

int main() {
    int Primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int i = 2; i < 99; i += 2) {
        for (int j = 0; j < 25; j++) {
            if (Primes[j] >= i)break;
            for (int k = j; k < 25; k++) {
                if (Primes[j] + Primes[k] == i)
                    printf("%d=%d+%d\n", i, Primes[j], Primes[k]);
                else if (Primes[j] + Primes[k] > i) {
                    break;
                }
            }
        }
    }
    return 0;
}