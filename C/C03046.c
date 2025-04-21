#include <stdio.h>
#include <math.h>
#define ll long long
int check(int n)
{
	int s = 0, k = 0, x = n;
	while (n)
	{
		if (n % 10 == 4)
			return 0;
		s += n % 10;
		k = k*10 + n % 10;
		n /= 10;
	}
	if (s % 10 == 0 && k == x)
		return 1;
	return 0;
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int l = pow(10, n - 1) + 1, r = pow(10, n) - 1;
		for (int i = l; i <= r; i++)
		{
			if (check(i))
				printf("%d ", i);
		}
		printf("\n");
	}
}
