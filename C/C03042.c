#include <stdio.h>
int check(int n)
{
	int x = n % 10;
	n /= 10;
	while (n)
	{
		if (n % 10 <= x)
			return 0;
		else
			x = n % 10;
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
			if (check(i))
				++cnt;
		}
		printf("%d\n", cnt);
	}
}
