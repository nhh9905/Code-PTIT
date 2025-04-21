#include <stdio.h>
#include <string.h>
int dd[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
int check(char s[])
{
	int l = 0, r = strlen(s) - 1;
	while (l < r)
	{
		if (!dd[s[l] - '0'] || !dd[s[r] - '0'])
			return 0;
		if (s[l++] != s[r--])
			return 0;
	}
	return 1;
}
int main()
{
	// freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[501];
		scanf("%s", s);
		if (check(s))
			printf("YES\n");
		else
			printf("NO\n");
	}
}