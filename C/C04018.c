#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
int main()
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a[35], cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
            if (i > 0 && a[i] == a[i - 1])
                ++cnt;
        }
        printf("%d\n", cnt);
    }
}