#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	void titlecase(char *);

	char str[50], out[sizeof(str) * 2];
	fgets(str, sizeof(str), stdin);
	titlecase(str);

	char *tok = strtok(str, " ");
	strcpy(out, tok), out[1] = '.', out[2] = '\0', tok = strtok(NULL, " ");
	while (tok) strcat(out, " "), strcat(out, tok), tok = strtok(NULL, " ");
	fputs(out, stdout);
}

void titlecase(char s_[])
{
	s_[0] = toupper(s_[0]);
	for (int i = 1; s_[i] != '\0'; i++) s_[i] = s_[i - 1] == ' ' ? toupper(s_[i]) : tolower(s_[i]);
}
