#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		int x = i, dd = 0;
		if (x > 1) 
			dd = 1;
		for (int j = 1; j <= n; j++)
		{
			printf("%d", x);
			if (!dd)
				++x;
			else
				--x;
			if (x == 1)
				dd = 0;
		}
		printf("\n");
	}
}
