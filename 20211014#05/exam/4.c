#include <stdio.h>

int main(int argc, const char *argv[])
{
	short a = -32768,
		  b = 1,
		  c = a - b;

	printf("c=%d\n", c);

	printf("%6d\n", 55);
	printf("-%5d\n", 10);
	printf("-----\n");
	printf("%6d\n", 55 - 10);
	printf("%08.2lf\n", 123.456);
	printf("\\%-11.9s\\", "Hello Kitty");

	return 0;
}
