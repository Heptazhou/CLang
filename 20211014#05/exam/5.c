#include <stdio.h>

int main(int argc, const char *argv[])
{
	void swap(int *, int *);

	int x, y, z;
	printf("Input three integer:\n");
	scanf("%d %d %d", &x, &y, &z);

	swap(&x, &y);
	swap(&y, &z);

	printf("\ec%d %d %d\n", x, y, z);
}

void swap(int *l, int *r) { *l ^= *r, *r ^= *l, *l ^= *r; }
