#include <stdio.h>
struct sv
{
	char ten[105];
	int id;
	float m1, m2, m3;
} a[1005];
typedef struct sv sv;
int cnt = 0;
void nhap(sv *x)
{
	scanf("\n");
	gets(x->ten);
	scanf("%f%f%f", &x->m1, &x->m2, &x->m3);
}
void in(sv a[])
{
	for (int i = cnt; i >= 1; i--)
		printf("%d %s %.1f %.1f %.1f\n", a[i].id, a[i].ten, a[i].m1, a[i].m2, a[i].m3);
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int cn;
	while (scanf("%d", &cn) != -1)
	{
		int k;
		if (cn == 1)
		{
			scanf("%d", &k);
			for (int i = 1; i <= k; i++)
			{
				nhap(&a[++cnt]);
				a[cnt].id = cnt;
			}
			printf("%d\n", k);
		}
		if (cn == 2)
		{
			scanf("%d", &k);
			printf("%d\n", k);
			nhap(&a[k]);
		}
		if (cn == 3)
		{
			in(a);
			break;
		}
	}
}
