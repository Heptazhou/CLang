#include <stdio.h>

int main(int argc, char const *argv[])
{
	void
	multiple_next_println(int, int);
	multiple_next_println(365, 7);
	multiple_next_println(12258, 23);
	multiple_next_println(996, 4);
}

int _multiple_next_a(int i, int j) { return i / j * j + j; }
int _multiple_next_b(int i, int j) { return i + j - i % j; }
void multiple_next_println(int i, int j)
{
	int k = _multiple_next_b(i, j);
	printf("%i\t%i\t%i\n", i, j, k);
}
