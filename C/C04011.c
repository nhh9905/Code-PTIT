#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, x[51], cnt = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &x[i]);
		int max = x[1];
		for (int i = 2; i <= n; i++)
		{
			if (x[i] >= max)
			{
				++cnt;
				max = x[i];
			}
		}
		printf("%d\n", cnt);
	}
}
