#include <stdio.h>
#include <stdbool.h>
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
bool check(int a, int b, int c, int d)
{
	if (gcd(a, b) == gcd(c, d))
		return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (check(a, b, c, d))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
