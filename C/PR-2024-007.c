#include <stdio.h>
#include <string.h>
typedef struct data
{
	char str[50];
	double num;
} data;
void sort(data *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].num > a[j].num)
			{
				data tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void print(data* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%s ", a[i].str);
	printf("\n");
	for (int i = 0; i < n; ++i)
		printf("%.3lf ", a[i].num);
	printf("\n");
}
void solve(data* a, int n)
{
	int ok = 1;
	while (n)
	{
		if (!ok)
		{
			sort(a, n);
			print(a, n);
			ok = 1;
		}
		strcat(a[0].str, a[1].str);
		a[0].num += a[1].num;
		for (int i = 1; i < n - 1; ++i)
			a[i] = a[i + 1];
		--n;
		for (int i = 1; i < n; ++i)
		{
			if (a[i].num < a[i - 1].num)
			{
				ok = 0;
				break;
			}
		}
		print(a, n);
	}
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		data a[n];
		for (int i = 0; i < n; ++i)
			scanf("%s ", a[i].str);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &a[i].num);
		sort(a, n);
		print(a, n);
		solve(a, n);
		printf("\n");
	}
}
