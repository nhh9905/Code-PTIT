#include <stdio.h>
#include <math.h>
int check(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}
int tong(int n)
{
	int ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int pt(int n)
{
	int ans = 0, x = n;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (check(x))
		{
			ans += tong(x);
			break;
		}
		while (x % i == 0)
		{
			ans += tong(i);
			x /= i;
		}
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	if (tong(n) == pt(n))
		printf("YES");
	else
		printf("NO");
}
