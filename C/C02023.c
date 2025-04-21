#include <stdio.h>
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int x = max(m, n) + 2*'0';
	for (int j = 1; j <= n; j++)
		printf("%c", x);
	printf("\n");
	for (int i = 1; i < m; i++)
	{
		int cnt = i, k = x;
		for (int j = 1; j <= n; j++)
		{
			printf("%c", k);
			if (cnt) 
			{
				k--;
				cnt--;
			}
		}
		printf("\n");
	}
}