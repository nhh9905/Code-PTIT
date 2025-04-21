#include <stdio.h>
#define ll long long
int main() 
{
	ll n;
	scanf("%lld", &n);
	int nt[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0}, d[10] = {0};
	while (n)
	{
		int k = n % 10;
		if (nt[k])
			d[k]++;
		n /= 10;
	}
	for (int i = 2; i <= 7; i++)
	{
		if (d[i])
			printf("%d %d\n", i, d[i]);
	}
}
