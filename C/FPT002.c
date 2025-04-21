#include <stdio.h>
void nhan(int a[][101], int b[][101], int c[][101], int m, int n, int p)
{
	int row = 1, col = 1;
	while (row <= m || col <= p)
	{
		c[row][col] = 0;
		for (int i = 1; i <= n; i++)
			c[row][col] += a[row][i]*b[i][col];
		++col;
		if (col > p)
		{
			if (row == m)
				break;
			col = 1;
			++row;
		}
	}
}
int main()
{
	int m, n, p, q;
	scanf("%d%d%d%d", &m, &n, &p, &q);
	int a[101][101], b[101][101], c[101][101], e[101][101], d[101][101];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= p; j++)
			scanf("%d", &b[i][j]);
	}
	nhan(a, b, e, m, n, p);
	for (int i = 1; i <= p; i++)
	{
		for (int j = 1; j <= q; j++)
			scanf("%d", &c[i][j]);
	}
	nhan(e, c, d, m, p, q);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= q; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
}