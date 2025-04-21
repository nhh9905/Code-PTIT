#include <stdio.h>
int main()
{
	// freopen("a.inp", "r", stdin);
	int t, m, n;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++)
	{
		printf("Test %d:\n", k);
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; i++)
		{
            int x;
			for (int j = 1; j <= n; j++)
            {
                scanf("%d", &x);
                if (i != 1 && j != 1)
                    printf("%d ", x);
            }
            if (i != 1)
                printf("\n");
		}
	}
}