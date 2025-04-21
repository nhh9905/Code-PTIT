#include <stdio.h>
int main()
{
	int n, x = 1;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			if (j == 1 || j == x)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
		++x;
	}
	for (int i = 1; i <= n; i++)
		printf("*");
}
