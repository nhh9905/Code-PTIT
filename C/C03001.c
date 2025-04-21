#include <stdio.h>
int tong(int n)
{
	int res = 0;
	while (n)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (tong(n) % 10 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
