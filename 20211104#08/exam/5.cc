#include <stdio.h>

int main(int argc, char const *argv[])
{
	long n, m = 0;

	printf("Input an integer: ");
	scanf("%ld", &n);

	if (n < 0) n = -n;
	while (n > 0) m += n % 10, n /= 10;
	printf("%ld\n", m);
}
