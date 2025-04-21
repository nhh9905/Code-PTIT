#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
int main()
{
    // freopen("a.inp", "r", stdin);
    int n, a[105], x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = n - x; i < n; i++)
        printf("%d ", a[i]);
    for (int i = 0; i < n - x; i++)
        printf("%d ", a[i]);
}