#include <stdio.h>

int main(int argc, const char *argv[])
{
	void swap(int *, int *);

	printf("Input three integer:\n");
	int a, b, c;
	scanf("%i %i %i", &a, &b, &c);

	if (a < b) swap(&a, &b);
	if (a < c) swap(&a, &c);
	if (b < c) swap(&b, &c);

	printf("\ecIn descending order:\n%i\n%i\n%i\n", a, b, c);
}

void swap(int *l, int *r) { *l ^= *r, *r ^= *l, *l ^= *r; }
