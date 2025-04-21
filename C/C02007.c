#include <stdio.h>
int main()
{
	int n, x = 1;
	scanf("%d", &n);
	while (x <= n)
	{
		for (int i = 1; i <= x; i++)
			printf("*");
		printf("\n");
		++x;
	}
}
