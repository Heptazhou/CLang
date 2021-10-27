#include <stdio.h>

int main(int argc, char const *argv[])
{
	long x = 0;
	printf("Input an integer (-2^63 ~ 2^63-1): ");
	scanf("%ld", &x);
	printf("\ec%ld\n%#lx\n", x, x);
}
