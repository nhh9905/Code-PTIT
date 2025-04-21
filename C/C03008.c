#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool check(int n)
{
	int s = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			s += i + n/i;
	}
	if (sqrt(n) == round(sqrt(n)))
		s -= sqrt(n);
	return s == 2*n;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 6; i <= n; i++)
	{
		if (check(i))
			printf("%d ", i);
	}
}
