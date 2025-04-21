#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
    // freopen("a.inp", "r", stdin);
    int n, a[105], d[100005] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        d[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[a[i]])
        {
            printf("%d %d\n", a[i], d[a[i]]);
            d[a[i]] = 0;
        }
    }
}