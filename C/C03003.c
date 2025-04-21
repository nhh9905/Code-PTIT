#include <stdio.h>
#include <math.h>
const int max = 2e6;
int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	int dd[max + 5];
	dd[1] = 1;
	for (int i = 2; i <= sqrt(max); i++)
	{
		if (!dd[i])
		{
			++cnt;
			printf("%d\n", i);
			for (int j = i*i; j <= max; j += i)
				dd[j] = 1;
			if (cnt == n)
				return 0;
		}
	}
	for (int i = sqrt(max) + 1; i <= max; i++)
	{
		if (!dd[i])
		{
			++cnt;
			printf("%d\n", i);
			if (cnt == n)
				return 0;
		}
	}
	printf("%d", cnt);
}
