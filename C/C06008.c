#include <stdio.h>
#include <string.h>
typedef struct word
{
	char s[15];
	int cnt;
} word;
int n = 0;
word a[21];
int pos(int n, char x[], word a[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].s, x) == 0)
			return i;
	}
	return -1;
}
int main()
{
//	freopen("a.inp", "r", stdin);
	char s[105];
	gets(s);
	char *token = strtok(s, " ");
	while (token != NULL)
	{
		int k = pos(n, token, a);
		if (k == -1)
		{
			printf("%s ", token);
			strcpy(a[n].s, token);
			a[n].cnt++;
			++n;
		}
		else
			a[k].cnt++;
		token = strtok(NULL, " ");
	}
}
