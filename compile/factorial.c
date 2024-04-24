#include <stdio.h>
#include <stdlib.h>
#include <gmp.h> // Include the GMP header

// Function to calculate factorial of a number using GMP
void factorial(int n)
{
    mpz_t result;     // Declare a GMP integer
    mpz_init(result); // Initialize the integer

    mpz_fac_ui(result, n); // Calculate factorial

    // Print the factorial result
    gmp_printf("%Zd", result);

    mpz_clear(result); // Free the memory used by the GMP integer
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    factorial(n); // Call the factorial function
    return 0;
}
