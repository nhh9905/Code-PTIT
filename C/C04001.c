#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if ((x & 1) == 0)
				printf("%d ", x);
		}
		printf("\n");
	}
}
