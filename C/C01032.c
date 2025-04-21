#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
	// freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int x = n, cnt = 0, a[1005];
		ll s = 1;
		for (int i = 2; i <= sqrt(n); i++)
		{
			int dd = 0;
			while (x % i == 0 && x > 1)
			{
				if (!dd) 
				{
					a[++cnt] = i;
					dd = 1;
				}
				x /= i;
			}
		}
		if (x != 1)
			a[++cnt] = x;
		for (int i = 1; i <= cnt; i++)
			s *= a[i];
		printf("%lld\n", s);
	}
}