#include <stdio.h>
#define ll long long
ll ucln(ll a, ll b)
{
	if (b == 0)
		return a;
	return ucln(b, a % b);
}
ll bcnn(ll a, ll b)
{
	return (a*b)/ucln(a, b);
}
int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n%lld", ucln(a, b), bcnn(a, b));
}
