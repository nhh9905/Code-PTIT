#include <stdio.h>
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a*b)/gcd(a, b);
}
struct phanso
{
	int tu, mau;
};
typedef struct phanso phanso;
void nhap(phanso *x)
{
	scanf("%d%d", &x->tu, &x->mau);
}
void in(phanso x)
{
	printf("%d/%d ", x.tu, x.mau);
}
void rutgon(phanso *a)
{
	int k = gcd(a->tu, a->mau);
	a->tu /= k;
	a->mau /= k;
}
void quydong(phanso *a, phanso *b)
{
	int k = lcm(a->mau, b->mau);
	a->tu *= (k/a->mau);
	b->tu *= (k/b->mau);
	a->mau = k, b->mau = k;
}
phanso cong(phanso a, phanso b)
{
	phanso tong;
	tong.tu = a.tu + b.tu;
	tong.mau = a.mau;
	return tong;
}
phanso chia(phanso a, phanso b)
{
	phanso ans;
	ans.tu = a.tu*b.mau;
	ans.mau = a.mau*b.tu;
	return ans;
}
int t;
int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		phanso a, b;
		nhap(&a); nhap(&b);
		printf("Case #%d:\n", i);
		rutgon(&a); rutgon(&b);
		quydong(&a, &b);
		in(a); in(b);
		printf("\n");
		phanso tong = cong(a, b);
		rutgon(&tong); in(tong);
		printf("\n");
		phanso thuong = chia(a, b); rutgon(&thuong); in(thuong);
		printf("\n");
	}
}
