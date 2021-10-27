#include <stdio.h>

int main(int argc, char const *argv[])
{
	void sort(int *, int);

	int arr[] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 },
		len   = sizeof(arr) / sizeof(*arr);

	sort(arr, len);
	for (int i = 0; i < len; i++) printf("%3d\n", *(arr + i));
}

void swap(int *p, int *q) { *p ^= *q, *q ^= *p, *p ^= *q; }
void sort(int *a, int n)
{
	int d = 1;
	for (; d < n / 3; d++) d *= 3;
	for (; d > 0; d /= 3)
		for (int i = d; i < n; i++)
			for (int h = i; h >= d && *(a + h) < *(a + h - d); h -= d) swap(a + h, a + h - d);
}
