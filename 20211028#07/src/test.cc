// gcc -lgmp

#include <gmpxx.h>
#include <iostream>

int main(int argc, const char *argv[])
{
	unsigned n = 3000;

	printf("%d! =\n", n);
	mpz_class fact = 1;
	for (unsigned i = 2; i <= n; ++i) fact *= i;
	std::cout << fact.get_str(62) << "\n";
}
