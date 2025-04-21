#include <stdio.h>
typedef struct {
	int x, y;
} diem;
void nhap(diem *a)
{
	scanf("%d%d", &a->x, &a->y);
}
int main()
{
	diem a[4];
	int minx = 105, maxx = 0, miny = 105, maxy = 0, k;
	for (int i = 0; i < 4; i++) 
	{
		nhap(&a[i]);
		if (a[i].x > maxx)
			maxx = a[i].x;
		if (a[i].x < minx)
			minx = a[i].x;
		if (a[i].y > maxy)
			maxy = a[i].y;
		if (a[i].y < miny)
			miny = a[i].y;
	}
	if (maxy - miny > maxx - minx)
		k = maxy - miny;
	else
		k = maxx - minx;
	printf("%d", k*k);
}
