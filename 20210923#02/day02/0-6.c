#include <stdio.h>

int main(int argc, const char *argv[])
{
	long double num = (3.31e-8 * 2.01e-7) / (7.16e-6 + 2.01e-8);
	printf("%Le\n", num);
}
