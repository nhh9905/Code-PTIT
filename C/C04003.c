#include <stdio.h>
int check(int a[], int n)
{
	int l = 0, r = n + 1;
	while (l++ < r--)
	{
		if (a[l] != a[r])
			return 0;
	}
	return 1;
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, a[101];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (check(a, n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
