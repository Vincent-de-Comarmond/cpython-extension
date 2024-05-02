#include <stdio.h>
#include <stdbool.h>
#include "primefinderfunc.h"

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
