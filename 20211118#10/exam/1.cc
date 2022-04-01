#include <iostream>

#define TRUE 1

int main(int argc, const char *argv[])
{
	using namespace std;

	int i = 5, *ip = &i;
	cout << ip << "\n";

	int x, y;
	x = 10, y = 10, cout << x++ << "\n";
	x = 10, y = 10, cout << --y << "\n";
	x = 10, y = 10, cout << x + y-- << "\n";
	x = 10, y = 10, cout << ++y - x << "\n";

	int n = 1 + 2 / 3 * 4 + 1;
	cout << n << "\n";

	// int   A[5][4];
	// float B[4];
	// for (int i = 1; i <= 5; i++)
	// 	for (int j = 1; j <= 4; j++)
	// 		A[i][j] = 0;
	// for (int i = 0; i < 4; i++)
	// 	scanf("%f", B[i + 1]);
}

double sine(double n) { return n; }
