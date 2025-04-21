#include <stdio.h>
#include <string.h>
struct pikachu
{
	char p[100];
	int k, m, num;
};
typedef struct pikachu pikachu;
int maxx = 0, sum = 0;
char s[100];
void nhap(pikachu *x)
{
	scanf("%s%d%d", x->p, &x->k, &x->m);
	x->num = 0;
}
void xuli(pikachu *x)
{
	while (x->m >= x->k)
	{
		int res = x->m/x->k;
		x->num += res;
		x->m -= res*x->k;
		x->m += res*2;
	}
	sum += x->num;
	if (x->num > maxx)
	{
		maxx = x->num;
		strcpy(s, x->p);
	}
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		pikachu x;
		nhap(&x);
		xuli(&x);
	}
	printf("%d\n%s", sum, s);
}
