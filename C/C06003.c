#include <stdio.h>
#include <string.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	getchar();
	char s[205];
	while (t--)
	{
		int cnt = 0;
		gets(s);
		char *token = strtok(s, " ");
		while (token != NULL)
		{
			++cnt;
			token = strtok(NULL, " ");
		}
		printf("%d\n", cnt);
	}
}