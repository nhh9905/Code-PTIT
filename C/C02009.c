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
		for (int i = 1; i <= n - x; i++)
			printf("*");
		printf("\n");
		--x;
	}
}
