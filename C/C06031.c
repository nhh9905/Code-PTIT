#include <stdio.h>
#include <string.h>
int main()
{
	freopen("a.inp", "r", stdin);
	char s[55];
	scanf("%s", s);
	char x = '0';
	int cnt = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] > x)
		{
			printf("%c", s[i]);
			++cnt;
			x = s[i];
		}
	}
	printf("%d", cnt);
}
