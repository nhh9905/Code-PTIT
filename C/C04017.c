#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
bool nt[1005];
void sang()
{
    nt[1] = 1;
    for (int i = 2; i*i <= 1e3; i++)
    {
        if (!nt[i])
        {
            for (int j = i*i; j <= 1e3; j += i)
                nt[j] = 1;
        }
    }
}
int main()
{
    // freopen("a.inp", "r", stdin);
    sang();
    int n, a[105], cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (!nt[a[i]])
            ++cnt;
    }
    printf("%d ", cnt);
    for (int i = 0; i < n; i++)
    {
        if (!nt[a[i]])
            printf("%d ", a[i]);
    }
}