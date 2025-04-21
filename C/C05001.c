#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int a[m + 1][n + 1];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", a[j][i]);
		printf("\n");
	}
}