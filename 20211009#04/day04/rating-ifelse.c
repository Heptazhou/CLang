#include <stdio.h>

int main(int argc, char const *argv[])
{
	char const *rating(double);

	double n;
	printf("Input score (0 ~ 100):\n");
	scanf("%le", &n);

	if (n >= 0 && n <= 100)
		printf("\ecScore : %i\nRating: %s\n", (int) n, rating(n));
	else
		printf("\ecInvalid input.\n");
}

char const *rating(double score)
{
	if (score >= 100) return "A+";
	if (score >= 90) return "A";
	if (score >= 80) return "B";
	if (score >= 70) return "C";
	if (score >= 60) return "D";
	else return "F";
}
