#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	// freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("\n");
		char s[85];
		gets(s);
		char *token = strtok(s, " ");
		while (token != NULL)
		{
			token[0] = toupper(token[0]);
			for (int i = 1; i < strlen(token); i++)
				token[i] = tolower(token[i]);
			printf("%s ", token);
			token = strtok(NULL, " ");
		}
		printf("\n");
	}
}
