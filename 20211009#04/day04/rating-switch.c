#include <stdio.h>

int main(int argc, const char *argv[])
{
	const char *rating(double);

	double n;
	printf("Input score (0 ~ 100):\n");
	scanf("%le", &n);

	if (n >= 0 && n <= 100)
		printf("\ecScore : %i\nRating: %s\n", (int) n, rating(n));
	else
		printf("\ecInvalid input.\n");
}

const char *rating(double score)
{
	switch ((int) score / 10)
	{
		case 10: return "A+";
		case 9: return "A";
		case 8: return "B";
		case 7: return "C";
		case 6: return "D";
		default: return "F";
	}
}
