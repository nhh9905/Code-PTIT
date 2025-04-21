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
void pt(int n)
{
	printf("%d = ", n);
	if (nt(n)) 
	{
		printf("%d^1", n);
		return;
	}
	int x = n;
	for (int i = 2; i <= sqrt(x); i++)
	{
		int cnt = 0;
		while (n % i == 0)
		{
			++cnt;
			n /= i;
		}
		if (cnt)
		{
			if (n > 1)
				printf("%d^%d * ", i, cnt);
			else
				printf("%d^%d", i, cnt);
		}
	}
	if (n > 1)
		printf("%d^1", n);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		pt(n);
	}
}
