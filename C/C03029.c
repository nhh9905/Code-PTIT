#include <stdio.h>
#include <stdbool.h>
#define ll long long
bool check(ll n)
{
	while (n)
	{
		if (n % 2)
			return 0;
		n /= 10;
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll x;
		scanf("%lld", &x);
		if (check(x))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
