#include <stdio.h>
#include <stdbool.h>
int t, n, a[8];
bool ok;
void ktao()
{
	for (int i = 1; i <= n; i++)
		a[i] = 1;
}
void sinh()
{
	int i = n;
	while (i >= 1 && a[i] >= 9)
		--i;
	if (i == 0)
		ok = 0;
	else
	{
		a[i]++;
		for (int j = i + 1; j <= n; j++)
			a[j] = a[j - 1];
	}
}
void in()
{
	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);
	printf(" ");
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		ok = 1;
		scanf("%d", &n);
		ktao();
		while (ok)
		{
			in();
			sinh();
		}
		printf("\n");
	}
}
