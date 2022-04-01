#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i, j;
	scanf("%i %i", &i, &j);
	printf("%i", i + j - i % j);
}
