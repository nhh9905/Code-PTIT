#include <stdio.h>
#include <math.h>
int nt(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (nt(x))
				printf("%d ", x);
		}
		printf("\n");
	}
}
