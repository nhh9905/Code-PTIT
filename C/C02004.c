#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int x = n - 1;
	while (x >= 0)
	{
		for (int i = 1; i <= x; i++)
			printf("~");
		if (x == n - 1 || !x)
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
		--x;
	}
}
