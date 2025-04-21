#include <stdio.h>
#define ll long long
int check(ll n)
{
	if (n % 2 == 0)
		return 0;
	int chan = 0, le = 0;
	while (n)
	{
		if (n % 2)
			++le;
		else
			++chan;
		n /= 10;
	}
	if (chan >= le)
		return 0;
	return 1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll n;
		scanf("%lld", &n);
		if (check(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
