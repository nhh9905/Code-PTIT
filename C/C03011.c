#include <stdio.h>
#include <stdbool.h>
int f[10];
void ktao()
{
	f[0] = f[1] = 1;
	for (int i = 2; i <= 9; i++)
		f[i] = i*f[i - 1];
}
bool tong(int n)
{
	int res = 0, x = n;
	while (x)
	{
		res += f[x % 10];
		x /= 10;
	}
	return res == n;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
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
	for (int i = a; i <= min(50000, b); i++)
	{
		if (tong(i))
			printf("%d ", i);
	}
}
