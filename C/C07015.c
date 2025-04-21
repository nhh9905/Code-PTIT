#include <stdio.h>
#include <stdlib.h>
struct ThiSinh
{
	int ma;
	char ten[105], ns[105];
	float m1, m2, m3;
};
typedef struct ThiSinh ThiSinh;
int t, cnt = 1;
ThiSinh x[105];
float dmax = 0;
float max(float a, float b)
{
	if (a > b)
		return a;
	return b;
}
void nhap(ThiSinh *x)
{
	x->ma = cnt++;
	getchar();
	gets(x->ten);
	scanf("%s%f%f%f", x->ns, &x->m1, &x->m2, &x->m3);
	dmax = max(dmax, x->m1 + x->m2 + x->m3);
}
int cmp(const void *a, const void *b)
{
	ThiSinh *x = (ThiSinh*)a;
	ThiSinh *y = (ThiSinh*)b;
	float kc = x->m1 + x->m2 + x->m3 - (y->m1 + y->m2 + y->m3);
	if (kc > 0)
		return 1;
	if (kc < 0)
		return -1;
	if (kc == 0)
	{
		if (x->ma < y->ma)
			return 1;
		return -1;
	}
}
void in(ThiSinh x)
{
	printf("%d %s %s %.1f\n", x.ma, x.ten, x.ns, x.m1 + x.m2 + x.m3);
}
int main()
{
//	freopen("a.inp", "r", stdin);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		nhap(&x[i]);
	qsort(x, t + 1, sizeof(ThiSinh), cmp);
	for (int i = t; i >= 1; i--) 
	{
		if (x[i].m1 + x[i].m2 + x[i].m3 == dmax)
			in(x[i]);
	}
}
