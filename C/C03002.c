#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d", &n);
	int x[n + 5];
	x[1] = 0;
	for (int i = 2; i <= n; i++)
		x[i] = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (x[i])
		{
			for (int j = i*i; j <= n; j += i)
				x[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (x[i])
			printf("%d\n", i);
	}
}
