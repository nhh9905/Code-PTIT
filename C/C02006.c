#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int x = 0;
	while (x < m)
	{
		for (int i = 1; i <= x; i++)
			printf("~");
		if (x == 0 || x == m - 1)
		{
			for (int i = 1; i <= n; i++)
				printf("*");	
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == 1 || i == n)
					printf("*");
				else
					printf(".");
			}
		}
		printf("\n");
		++x;
	}
}
