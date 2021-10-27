#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y, z;
	printf("Input two integer:\n");
	scanf("%d %d", &x, &y);

	z = x + y - x % y;
	z /= y;

	if (x % y == 0) z -= 1;
	printf("\ec%d / %d = %d\n", x, y, z);
}
