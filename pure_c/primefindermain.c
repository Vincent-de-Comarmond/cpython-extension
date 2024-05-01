#include <stdio.h>
#include "primefinderfunc.h"

int main()
{

    int desiredPrimes;
    // ask user how many primes they want
    printf("enter desired number of primes: ");
    //store the range in variables using scanf
    scanf("%d", &desiredPrimes);
    printf("desired primes: %d:\n", desiredPrimes);
    long primes[desiredPrimes];
    generatePrimes(desiredPrimes, primes);

    for (int i = 0; i < desiredPrimes; i ++) {
        printf("%ld\n", primes[i]);
    }

    return 0;
}
