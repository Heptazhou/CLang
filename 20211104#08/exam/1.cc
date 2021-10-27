#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	auto a = 5, b = 10, c = -6;

	cout << (a == c || b > a) << " "
		 << (a < b && a > c) << "\n";

	auto x = 5, y = 0;

	(x && y) ? x = 10 : y = 10;

	cout << x << " "
		 << y << "\n";
}
