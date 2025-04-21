#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    // freopen("a.inp", "r", stdin);
    int n, maxx = 0, maxx2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        int x;
        scanf("%d", &x);
        maxx = max(maxx, x);
        if (x > maxx2 && x != maxx)
            maxx2 = x;
    }
    printf("%d %d", maxx, maxx2);
}