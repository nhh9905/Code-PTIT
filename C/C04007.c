#include <stdio.h>
int main()
{
	int m, n, p, a[105], b[105], res = 0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	scanf("%d", &p);
	for (int i = 0; i < m; i++)
	{
		if (i == p)
		{
			++res;
			for (int j = 0; j < n; j++)
				printf("%d ", b[j]);
		}
		printf("%d ", a[i]);
	}
	if (!res)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", b[j]);
	}
}
