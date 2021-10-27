#include <stdbool.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	void sort(int *, int);

	int arr[] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 },
		len   = sizeof(arr) / sizeof(arr[0]);

	sort(arr, len);
	for (int i = 0; i < len; i++) printf("%3d\n", arr[i]);
}

void swap(int *p, int *q) { *p ^= *q, *q ^= *p, *p ^= *q; }
void sort(int arr[], int n)
{
	if (n < 2) return;
	bool flag = false;
	for (int i = 1; i < n; i++)
		if (arr[i - 1] > arr[i]) swap(&arr[i - 1], &arr[i]), flag = true;
	if (flag) sort(arr, n - 1);
}
