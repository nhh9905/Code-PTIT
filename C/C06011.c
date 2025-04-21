#include <stdio.h>
#include <string.h>
int check(char s[])
{
	int l = 0, r = strlen(s) - 1, sum = 0;
	if (s[l] != '8' || s[r] != '8')
		return 0;
	while (l < r)
	{
		sum += s[l] - '0' + s[r] - '0';
		if (s[l] != s[r])
			return 0;
		++l;
		--r;
	}
	if (l == r)
		sum += s[l] - '0';
	if (sum % 10)
		return 0;
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