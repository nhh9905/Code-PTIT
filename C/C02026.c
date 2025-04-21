#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int x = m + 64, y = n + 64;
	if (x > y)
		x = y;
	int k = m + 64 - x;
	for (int i = 1; i <= m; i++)
	{
		int a = x;
		for (int j = 1; j <= n; j++)
		{
			printf("%c", a);
			if (a < y) 
				++a;
		}
		printf("\n");
		if (k)
			--k;
		else
			--x;
	}
}
