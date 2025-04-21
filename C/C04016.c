#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
bool nt[100005];
void sang()
{
    nt[1] = 1;
    for (int i = 2; i*i <= 1e5; i++)
    {
        if (!nt[i])
        {
            for (int j = i*i; j <= 1e5; j += i)
                nt[j] = 1;
        }
    }
}
int cmp(const void *a, const void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;
    return *x - *y;
}
int main()
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    sang();
    for (int j = 1; j <= t; j++)
    {
        printf("Test %d:\n", j);
        int n, a[105], d[100005] = {0};
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (!nt[a[i]])
                d[a[i]]++;
        }
        qsort(a, n, sizeof(int), cmp);
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