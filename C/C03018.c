#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int f[10], d[30] = {0};
void ktao()
{
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 9; i++) 
	{
		f[i] = f[i - 1] + f[i - 2];
		d[f[i]] = 1;
	}
}
bool check(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}
int tong(int n)
{
	int s = 0;
	while (n)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}
void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a > b)
		swap(&a, &b);
	ktao();
	for (int i = a; i <= b; i++)
	{
		if (check(i) && d[tong(i)])
			printf("%d ", i);
	}	
}
