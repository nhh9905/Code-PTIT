#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int x = 'A';
	for (int i = 1; i <= m; i++)
	{
		int k = x, l, a = 1;
		for (int j = 1; j <= n; j++)
		{
			if (j == 1)
				l = k;
			if (k > n + 64) 
			{
				k = l - 1;
				a = 0;
			}
			printf("%c", k);
			if (a)
				k++;
			else
				k--;
		}
		printf("\n");
		if (x < n + 64)
			++x;
	}
}