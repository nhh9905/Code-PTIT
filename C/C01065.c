#include <stdio.h>
#define ll long long
int d[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
int main()
{
	// freopen("a.inp", "r", stdin);
	ll n;
	int cnt = 0, a[10] = {0};
	scanf("%lld", &n);
	while (n)
	{
		if (d[n % 10])
			a[n % 10]++;
		n /= 10;
	}
	for (int i = 2; i <= 7; i++)
	{
		if (d[i] && a[i])
			printf("%d %d\n", i, a[i]);
	}
}