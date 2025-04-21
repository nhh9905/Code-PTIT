#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
int cmp(const void *a, const void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;
    return *y - *x;
}
int main()
{
    // freopen("a.inp", "r", stdin);
    int n, a[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}