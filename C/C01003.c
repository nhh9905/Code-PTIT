#include <stdio.h>
#define ll long long
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		ll k = (ll)n*n;
		printf("%lld\n", k);
	}
}
