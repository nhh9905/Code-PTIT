#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, res = 0;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++) 
		{
			scanf("%d", &a[i]);
			if (a[i] > res)
				res = a[i];
		}
		printf("%d\n", res);
		for (int i = 0; i < n; i++)
		{
			if (a[i] == res)
				printf("%d ", i);
		}
		printf("\n");
	}
}