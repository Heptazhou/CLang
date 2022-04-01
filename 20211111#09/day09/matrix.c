#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	void Print(int *, int, int);
	void InitR(int *, int, int);
	void TriUp(int *, int, int);
	void TriLo(int *, int, int);

	int mat[5][5],
		row = sizeof(mat) / sizeof(*mat),
		col = sizeof(*mat) / sizeof(**mat);

	InitR(&**mat, row, col);
	TriUp(&**mat, row, col);
	Print(&**mat, row, col);
}

void Print(int mat[], int row, int col)
{
	for (int i = 0; i < row; i++, printf("\n"))
		for (int j = 0; j < col; j++) printf("%4d ", mat[col * i + j]);
}

void InitR(int mat[], int row, int col)
{
	srand(time(0));
	for (int i = 0; i < row * col; i++) mat[i] = rand() % 100 + 1;
}

void TriUp(int mat[], int row, int col)
{
	for (int i = row; i > 1; i--)
		for (int j = 1; j < i; j++)
			mat[col * (i - 1) + j - 1] = 0;
}

void TriLo(int mat[], int row, int col)
{
	for (int i = 1; i < row; i++)
		for (int j = col; j > i; j--)
			mat[col * (i - 1) + j - 1] = 0;
}
