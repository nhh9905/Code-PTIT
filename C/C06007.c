#include <stdio.h>
#include <string.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	char s[105], k[15];
	gets(s);
	scanf("%s", k);
	char *token = strtok(s, " ");
	while (token != NULL)
	{
		if (strcmp(token, k))
			printf("%s ", token);
		token = strtok(NULL, " ");
	}
}
