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
void pt(int n)
{
	int k = n;
	for (int i = 2; i <= sqrt(k); i++)
	{
		int cnt = 0;
		while (n % i == 0)
		{
			cnt++;
			n /= i;
		}
		if (cnt)
			printf("%d(%d) ", i, cnt);
		if (check(n)) 
		{
			printf("%d(1)", n);
			break;
		}
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int n;
		scanf("%d", &n);
		printf("Test %d: ", i);
		if (check(n))
			printf("%d(1)", n);
		else
			pt(n);
	}
}
