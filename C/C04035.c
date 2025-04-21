#include <stdio.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	int n, min_up = 50005, min_down = 50005, sum_up = 0, sum_down = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		int u, d;
		scanf("%d%d", &u, &d);
		sum_up += u;
		sum_down += d;
		if (u < min_up)
			min_up = u;
		if (d < min_down)
			min_down = d;
	}
	sum_up += min_down;
	sum_down += min_up;
	if (sum_up < sum_down)
		printf("%d", sum_down);
	else
		printf("%d", sum_up);
}
