#include <stdio.h>
int main()
{
	int n, a[100005], cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x]++;
		a[y]++;
		if (a[x] == n - 1 || a[y] == n - 1)
		{
			printf("Yes");
			cnt = 1;
			return 0;
		}
	}
	if (!cnt)
		printf("No");
}
