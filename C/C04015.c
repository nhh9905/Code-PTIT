#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int j = 1; j <= t; j++)
    {
        printf("Test %d:\n", j);
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
                printf("%d xuat hien %d lan\n", a[i], d[a[i]]);
                d[a[i]] = 0;
            }
        }
    }
}