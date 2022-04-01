#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	void sort(int *, int);

	FILE *io = NULL;
	int   arr[1048576], len = sizeof(arr) / sizeof(arr[0]);

	io = fopen("1048576.txt", "r");
	for (int i = 0; i < len; i++) fscanf(io, "%d", &arr[i]);
	fclose(io);

	clock_t TB = clock();
	sort(arr, len);
	clock_t TE = clock();
	printf("\tshell %12.3f ms\n", (double) (TE - TB) / (CLOCKS_PER_SEC / 1000));

	// io = fopen("1048576_shell.txt", "w");
	// for (int i = 0; i < len; i++) fprintf(io, "%d\n", arr[i]);
	// fclose(io);
}

void swap(int *p, int *q) { *p ^= *q, *q ^= *p, *p ^= *q; }
void sort(int arr[], int n)
{
	int d = 1;
	for (; d < n / 3; d++) d *= 3;
	for (; d > 0; d /= 3)
		for (int i = d; i < n; i++)
			for (int h = i; h >= d && arr[h] < arr[h - d]; h -= d) swap(&arr[h], &arr[h - d]);
}
