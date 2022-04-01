#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n = 9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++) printf("  ");
		for (int j = 1; j <= i - 1; j++) printf("%d   ", i);
		printf("%d\n", i);
	}
}
