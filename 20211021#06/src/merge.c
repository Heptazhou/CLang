// gcc -fsplit-stack

#include <stdio.h>
#include <time.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(int argc, char const *argv[])
{
	void sort(int *, int);

	FILE *io = NULL;
	int   arr[1048576];
	int   len = sizeof(arr) / sizeof(arr[0]);

	io = fopen("1048576.txt", "r");
	for (int i = 0; i < len; i++) fscanf(io, "%d", &arr[i]);
	fclose(io);

	clock_t TB = clock();
	sort(arr, len);
	clock_t TE = clock();
	printf("\tmerge %12.3f ms\n", (double) (TE - TB) / (CLOCKS_PER_SEC / 1000));

	// io = fopen("1048576_merge.txt", "w");
	// for (int i = 0; i < len; i++) fprintf(io, "%d\n", arr[i]);
	// fclose(io);
}

void _copy_arr(int B[], int A[], int n)
{
	for (int i = 0; i < n; i++) A[i] = B[i];
}
void _merge(int A[], int iLeft, int iRight, int iEnd, int B[])
{
	int i = iLeft, j = iRight;
	for (int k = iLeft; k < iEnd; k++)
		if (i < iRight && (j >= iEnd || A[i] <= A[j])) B[k] = A[i], i++;
		else B[k] = A[j], j++;
}
void sort(int arr[], int length)
{
	int tmp[length];
	for (long width = 1; width < length; width *= 2)
	{
		for (long i = 0; i < length; i += width * 2) _merge(arr, i, MIN(i + width, length), MIN(i + width * 2, length), tmp);
		_copy_arr(tmp, arr, length);
	}
}
