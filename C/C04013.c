#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
int main()
{
    // freopen("a.inp", "r", stdin);
    int n, a[105], cnt = 0, d[100005] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        d[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[a[i]] == 1)
            ++cnt;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
    {
        if (d[a[i]] == 1)
            printf("%d ", a[i]);
    }
}