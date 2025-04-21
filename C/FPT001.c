#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int x = n - 1, y = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= y; j++)
			printf("0 ");
		for (int j = 1; j <= x; j++)
			printf("%d ", j);
		printf("\n");
		++y;
		--x;
	}
}