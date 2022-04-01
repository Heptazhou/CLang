#include <stdio.h>

int main(int argc, const char *argv[])
{
	void
	fibonacci(int);
	fibonacci(12);
}

void fibonacci(int n)
{
	int a = 1, b = 1, c;
	for (int i = 0; i < n; i++) printf("%d\n", a), c = a + b, a = b, b = c;
}
