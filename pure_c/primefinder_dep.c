#include <stdio.h>
#include <stdbool.h>
int main()
{

    int current_prime=2, desired_primes;
    long current_value=3, previous_value=2;

    // Ask user how many primes they want
    printf("Enter desired number of primes: ");
    //Store the range in variables using scanf
    scanf("%d", &desired_primes);
    printf("Desired primes: %d:\n", desired_primes);

    // Array to store primes in
    long primes[desired_primes];
    primes[0] = 2, primes[1] = 3;

    //Display prime numbers for input range
    printf("Generating first %d prime numbers:\n", desired_primes);

    while (current_prime < desired_primes) {
        previous_value = current_value;
        current_value += 1;

        // printf("Current value: %ld, Current prime: %d\n", current_value, current_prime); // Debugging
        bool isprime = true;
        for (int i = 0 ; i < current_prime; i ++) {
            // printf("Testing prime: %ld\n", primes[i]); // Debugging
            if (current_value % primes[i] == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            primes[current_prime] = current_value;
            current_prime +=1;
        }
    }


    for (int i = 0; i < current_prime; i ++) {
        printf("%ld\n",primes[i]);
    }


    return 0;
}
