// gcc -lgmp

#include <gmp.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	void factorial(unsigned, mpz_t);

	unsigned n = 1000;

	printf("%d! =\n", n);
	mpz_t fact;
	mpz_init(fact);
	factorial(n, fact);
	mpz_out_str(stdout, 10, fact);
	mpz_clear(fact);
	printf("\n");
}

void factorial(unsigned n, mpz_t result)
{
	mpz_set_ui(result, 1);
	while (n > 1) { mpz_mul_ui(result, result, n), n--; }
}
