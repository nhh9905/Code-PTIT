#include <stdio.h>
#include <math.h>
int main()
{
	// freopen("a.inp", "r", stdin);
	int n;
	scanf("%d", &n);
	int x = n;
	for (int i = 2; i <= sqrt(n); i++)
	{
		while (x % i == 0 && x > 1)
		{
			printf("%d", i);
			x /= i;
			if (x != 1)
				printf("x");
		}
	}
	if (x != 1)
		printf("%d", x);
}