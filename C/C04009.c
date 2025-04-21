#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
//	freopen("a.inp", "r", stdin);
	int n, a[105];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
			printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % 2)
			printf("%d ", a[i]);
	}
}
