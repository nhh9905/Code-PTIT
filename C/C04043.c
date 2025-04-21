#include <stdio.h>
#include <stdlib.h>
#define ll long long
int cmp(const void *a, const void *b)
{
	ll *x = (ll*)a;
	ll *y = (ll*)b;
	if (*x < *y)
		return -1;
	return 1;
}
int check(ll a[], int n)
{
	for (int i = n - 1; i >= 2; i--)
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			if (a[l] + a[r] == a[i])
				return 1;
			else
			{
				if (a[l] + a[r] < a[i])
					l++;
				else
					r--;
			}
		}
	}
	return 0;
}
int main() 
{
	// freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		ll a[n];
		for (int i = 0; i < n; i++)
		{
			ll x;
			scanf("%lld", &x);
			a[i] = x*x;
		}
		qsort(a, n, sizeof(ll), cmp);
		if (check(a, n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}