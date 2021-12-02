#include <stdio.h>

void f()
{
	static int a = 2;
	a += 2, printf("%d,", a);
}

int main()
{
	for (int c = 1; c < 5; c++) f();
}
