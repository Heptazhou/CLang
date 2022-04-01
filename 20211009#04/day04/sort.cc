#include <iostream>

int main(int argc, const char *argv[])
{
	using std::cin;
	using std::swap;

	printf("Input three integer:\n");
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);

	printf("\ecIn descending order:\n%i\n%i\n%i\n", a, b, c);
}
