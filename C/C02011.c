#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		int x = i, dd = 0;
		for (int j = 1; j <= n; j++)
		{
			if (x >= n + 1) 
			{
				if (j == 1) 
				{
					printf("%d", x);
					x = i - 1;
					++j;
				}
				else
					x = n - 1;
				dd = 1;
			}
			printf("%d", x);
			if (!dd)
				++x;
			else
				--x;
		}
		printf("\n");
	}
}
