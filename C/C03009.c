#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool shh(int n)
{
	int s = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			s += i + n/i;
	}
	if (sqrt(n) == round(sqrt(n)))
		s -= sqrt(n);
	return s == 2*n;
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
	for (int i = a; i <= b; i++)
	{
		if (shh(i))
			printf("%d ", i);
	}
}
