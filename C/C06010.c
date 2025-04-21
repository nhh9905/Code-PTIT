#include <stdio.h>
int check(char s[])
{
	int l = 0, r = strlen(s) - 1;
	while (l < r)
	{
		if (s[l] != s[r] || s[l] % 2 || s[r] % 2)
			return 0;
		++l;
		--r;
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