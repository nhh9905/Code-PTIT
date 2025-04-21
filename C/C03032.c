#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool nt(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}
bool tong(int n)
{
	while (n)
	{
		if (!nt(n % 10))
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
		int a, b, cnt = 0;
		scanf("%d%d", &a, &b);
		for (int i = a; i <= b; i++)
		{
			if (nt(i) && tong(i))
				++cnt;
		}
		printf("%d\n", cnt);
	}
}
