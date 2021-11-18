#include <stdio.h>

#define sum(a, b) a + b

int x = 10, y = 2, u, v;

void num()
{
	int x = 3;
	u = x * y, v = x + y;
	printf("%d, %d\n", u, v);
}

int main()
{
	x = 7, y = 5;
	num();

	char *p, s[] = "continue";
	p = s;
	while (*p != 'i') printf("%c", *p - 32), p++;
	printf("\n");

	int t[10], *q = &t[2];
	for (int i = 0; i < 10; i++) t[i] = i, printf("%d ", t[i]);
	printf("\n");
	printf("%d\n", q[7]);

	int n = 5 * sum(3 + 1, 2);
	printf("%d\n", n);
}
