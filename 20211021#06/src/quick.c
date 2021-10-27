#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	void sort(int *, int, int);

	FILE *io = NULL;
	int   arr[1048576], len = sizeof(arr) / sizeof(arr[0]);

	io = fopen("1048576.txt", "r");
	for (int i = 0; i < len; i++) fscanf(io, "%d", &arr[i]);
	fclose(io);

	clock_t TB = clock();
	sort(arr, 0, len - 1);
	clock_t TE = clock();
	printf("\tquick %12.3f ms\n", (double) (TE - TB) / (CLOCKS_PER_SEC / 1000));

	// io = fopen("1048576_quick.txt", "w");
	// for (int i = 0; i < len; i++) fprintf(io, "%d\n", arr[i]);
	// fclose(io);
}

void swap(int *p, int *q) { *p ^= *q, *q ^= *p, *p ^= *q; }

int _partition(int arr[], int l, int h)
{
	int p = arr[l + (h - l) / 2],
		i = l - 1,
		j = h + 1;
	for (;;)
	{
		do i++;
		while (arr[i] < p);
		do j--;
		while (arr[j] > p);
		if (i >= j) return j;
		swap(&arr[i], &arr[j]);
	}
}
void sort(int arr[], int l, int h)
{
	if (l < 0 || h < 0 || l >= h) return;
	int p = _partition(arr, l, h);
	sort(arr, l, p);
	sort(arr, p + 1, h);
}
