#include <stdio.h>
int main()
{
	int m, n, k;
	scanf("%d%d", &m, &n);
	int x = 'A', y = 'A';
	printf("@");
	for (int i = 1; i < n; i++)
	{
		if (i == n - 1)
			k = x;
		printf("%c", x);
		x++;
	}
	printf("\n");
	x = 'A';
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%c", x);
			if (x < k)
				x++;
		}
		if (y < k)
			x = ++y;
		printf("\n");
	}
}