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
int main()
{
	int n;
	scanf("%d", &n);
	ktao();
	for (int i = 1; i <= min(50000, n); i++)
	{
		if (tong(i))
			printf("%d ", i);
	}
}
