#include <stdio.h>
#include <math.h>
const int max = 1e5;
int x[7];
int tn(int n)
{
	int cnt = 0;
	while (n)
	{
		x[++cnt] = n % 10;
		n /= 10;
	}
	int l = 1, r = cnt;
	while (l <= r)
	{
		if (x[l] != x[r])
			return 0;
		++l;
		--r;
	}
	return 1;
}
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
		int a, b;
		scanf("%d%d", &a, &b);
		int dem = 0;
		for (int i = a; i <= b; i++)
		{
			if (nt(i) && tn(i))
			{
				printf("%d ", i);
				++dem;
			}
			if (dem == 10 && dem > 0) 
			{
				printf("\n");
				dem = 0;
			}
		}
		if (dem)
			printf("\n");
	}	
}
