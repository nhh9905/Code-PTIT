#include <stdio.h>
#include <stdlib.h>
struct hang
{
	char ten[105], nhom[105];
	float mua, ban;
	int stt;
};
typedef struct hang hang;
int t, cnt = 1;
hang x[105];
void nhap(hang *x)
{
    x->stt = cnt++;
	getchar();
	gets(x->ten);
	gets(x->nhom);
	scanf("%f%f", &x->mua, &x->ban);
}
void in(hang x)
{
	printf("%d %s %s %.2f\n", x.stt, x.ten, x.nhom, x.ban - x.mua);
}
int cmp(const void *a, const void *b)
{
	hang *x = (hang*)a;
	hang *y = (hang*)b;
	float loi = x->ban - x->mua - (y->ban - y->mua);
	if (loi > 0)
		return 1;
	if (loi < 0)
		return -1;
	return 0;
}
int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) 
		nhap(&x[i]);
	qsort(x, t + 1, sizeof(hang), cmp);
	for (int i = t; i >= 1; i--)
		in(x[i]);
}
