#include <stdio.h>
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	int k = max(m, n);
	for (int i = m; i >= 1; i--)
	{
		int x = k--;
		for (int j = x; j >= max(x - n + 1, 1); j--)
			printf("%d", j);
		if (x != n)
		{
			for (int j = 2; j <= n - x + 1; j++)
				printf("%d", j);
		}
		printf("\n");
	}
}
