#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		printf("*");
	printf("\n");
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == 1 || j == n)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
		printf("*");
	printf("\n");
}
