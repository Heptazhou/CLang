#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("%g\n", pow(0x100, sizeof(short)) / 2);
	printf("%g\n", pow(0x100, sizeof(int)) / 2);
	printf("%g\n", pow(0x100, sizeof(long)) / 2);
	printf("%g\n", pow(0x100, sizeof(float)) / 2);
	printf("%g\n", pow(0x100, sizeof(double)) / 2);

	return 0;
}
