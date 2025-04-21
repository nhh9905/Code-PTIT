#include <stdio.h>
#include <stdbool.h>
#define ll long long
int main()
{
//	freopen("a.inp", "r", stdin);
	int n, a[105], d[10005], cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		d[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[a[i]] > 1)
		{
			cnt = 1;
			printf("%d ", a[i]);
			d[a[i]] = 0;
		}
	}
	if (!cnt)
		printf("0");
}