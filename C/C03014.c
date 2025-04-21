#include <stdio.h>
#define ll long long
int t;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
ll lcm(int a, int b)
{
	return (1ll*a*b)/(1ll*gcd(a, b));
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld %d\n", lcm(a, b), gcd(a, b));
	}
}
