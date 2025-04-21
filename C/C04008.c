#include <stdio.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int j = 1; j <= t; j++)
	{
		int n, m, p, a[105], b[105];
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		printf("Test %d:\n", j);
		for (int i = 0; i < n; i++)
		{
			if (i == p)
			{
				for (int k = 0; k < m; k++)
					printf("%d ", b[k]);
			}
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}
