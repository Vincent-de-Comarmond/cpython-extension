// #include <stdio.h> Standard Input-Output ... we don't really need it here - it was needed when we were doing the printf
#include <stdbool.h> // Import to get booleans

/**
 * Function to populate an array containing the prime numbers (as longs).
 * @param int desiredPrimes: The number of prime numbers to be computed
 * @param long primeNumbers[]: Array of longs which will hold the computed primes
 * @return void - returns nothing
 */
void generatePrimes(int desiredPrimes, long primeNumbers[]) {

    // Give this the first 2 primes to bootstrap
    int currentPrime=2; // position of current prime number
    long currentValue = 3l; // value of current prime number
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
