#include <gmp.h>
#include <stdlib.h>

// Function to calculate factorial of a number using GMP and return as a string
char *factorial(int n)
{
    mpz_t result;     // Declare a GMP integer
    mpz_init(result); // Initialize the integer

    mpz_fac_ui(result, n); // Calculate factorial

    // Allocate memory for the string representation of the factorial result
    char *str_result = (char *)malloc(1024); // Adjust the size as needed

    // Convert the GMP integer to a string
    gmp_sprintf(str_result, "%Zd", result);

    // Clear the memory used by the GMP integer
    mpz_clear(result);

    return str_result; // Return the string representation of the factorial result
}