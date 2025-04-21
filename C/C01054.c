#include <stdio.h>
#define ll long long
int d[2000005];
void sang()
{
	d[1] = 0;
	for (int i = 2; i <= 2e6; i++)
	{
		if (!d[i])
		{
			d[i] = i;
			for (ll j = 1ll*i*i; j <= 2e6; j += i)
				d[j] = i;
		}
	}
}
int main()
{
	// freopen("a.inp", "r", stdin);
	int t;
	ll s = 0;
	scanf("%d", &t);
	sang();
	while (t--)
	{
		int n;
		scanf("%d", &n);
		while (n > 1)
		{
			s += d[n];
			n /= d[n];
		}
	}
	printf("%lld\n", s);
}