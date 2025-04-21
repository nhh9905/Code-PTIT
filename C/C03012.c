#include <stdio.h>
int n, f[25];
int main()
{
	scanf("%d", &n);
	f[0] = f[1] = 1;
	for (int i = 2; i <= 20; i++) 
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] == n)
		{
			printf("1");
			return 0;
		}
	}
	printf("0");
}
