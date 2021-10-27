#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	int m = 1;

	while (m < 10) printf("%d,", m), m++;
	cout << "\n";

	// while (scanf("%d", &m) != -1) printf("%d,", m);

	int n = 0, sum = 0;
	for (; n < 10; sum += n, n++) { }

	cout << n << "\n"
		 << sum << "\n";
}
