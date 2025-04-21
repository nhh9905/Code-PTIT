#include <stdio.h>
#include <string.h>
void dx(char c[])
{
	int l = 0, r = strlen(c) - 1, cnt = 1;
	while (l < r)
	{
		if (c[l] != c[r]) 
		{
			if (!cnt)
			{
				printf("NO\n");
				return;
			}
			c[l] = c[r];
			--cnt;
		}
		++l, --r;
	}
	if (!cnt)
		printf("YES\n");
	else
	{
		if (strlen(c) % 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("\n");
		char c[25];
		gets(c);
		dx(c);
	}
}
