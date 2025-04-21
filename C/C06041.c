#include <stdio.h>
#include <string.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	char s[100005], z[100005];
	scanf("%s", s);
	int cnt = 0;
	char x = 'a';
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		if (s[i] >= x) 
		{
			z[++cnt] = s[i];
			x = s[i];
		}
	}
	for (int i = cnt; i >= 1; i--)
		printf("%c", z[i]);
}
