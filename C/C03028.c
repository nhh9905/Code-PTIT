#include <stdio.h>
int main()
{
	int n, k = 1, a[11][11] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) 
		{
			if (j > 1)
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
