#include <stdio.h>
#include <stdbool.h>
#define ll long long
bool d[1000005];
int a[1000005], n = 0;
void sang()
{
	for (int i = 2; i <= 1e3; i++)
	{
		if (!d[i])
		{
			for (int j = i*i; j <= 1e6; j += i)
				d[j] = 1;
		}
	}
	for (int i = 2; i <= 1e6; i++)
	{
		if (!d[i])
			a[n++] = i;
	}
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	sang();
	while (t--)
	{
		int cnt = 0;
		ll l, r;
		scanf("%lld%lld", &l, &r);
		for (int i = 0; i < n; i++)
		{
			if ((ll)a[i]*a[i] >= l && (ll)a[i]*a[i] <= r)
				++cnt;
		}
		printf("%d\n", cnt);
	}
}
