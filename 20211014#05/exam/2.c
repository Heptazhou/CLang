#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	double F = 95;
	double C = (F - 32) * 5 / 9;
	printf("%g\n", C);

	double x = 2.55;
	double Y = 3 * pow(x, 3) - 5 * pow(x, 2) + 6;
	printf("%g\n", Y);

	return 0;
}
