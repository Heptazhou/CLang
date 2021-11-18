#include <cmath>

int main() { }

int prime(int n)
{
	if (n <= 1) return 0;
	for (int i = 2; i <= (int) sqrt(n); i++)
		if (n % i == 0) return 0;
	return 1;
}
