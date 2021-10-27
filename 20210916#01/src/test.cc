#include <iostream>

#define PAUSE                               \
	printf("Press Enter to continue...: "); \
	fgetc(stdin);

int main(int argc, char const *argv[])
{
	int a = 75, b = 25, c = a + b;
	printf("Hello %i.\n", c);

	// PAUSE
	return 0;
}
