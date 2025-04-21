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
		for (int i = 1; i <= n; i++)
			printf("*");
		printf("\n");
		++x;
	}
}
