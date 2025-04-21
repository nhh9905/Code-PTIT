#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int x, k = 'A';
	for (int i = 1; i <= n; i++)
	{
		x = k;
		for (int j = 1; j <= n - i + 1; j++)
		{
			printf("%c", x);
			x += 2;
		}
		printf("\n");
		k += 2;
	}
}