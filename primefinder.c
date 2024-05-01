#include <stdio.h>
#include <stdbool.h>

void generatePrimes(int desiredPrimes, long primeNumbers[]) {

    // Give this the first 2 primes to bootstrap
    int currentPrime=2;
    long currentValue = 3l;
    primeNumbers[0]=2, primeNumbers[1]=currentValue;

    while (currentPrime < desiredPrimes) {
        currentValue++;

        // printf("Current value: %ld, Current prime: %d\n", currentValue, currentPrime); // Debugging
        bool isprime = true;
        for (int i = 0 ; i < currentPrime; i ++) {
            // printf("Testing prime: %ld\n", primes[i]); // Debugging
            if (currentValue % primeNumbers[i] == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            primeNumbers[currentPrime] = currentValue;
            currentPrime++;
        }
    }
}


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
