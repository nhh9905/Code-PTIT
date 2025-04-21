#include <stdio.h>
int t, n, x[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main()
{
    // freopen("a.inp", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        int cnt = 0;
        scanf("%d", &n);
        for (int i = 9; i >= 0; i--)
        {
            while (n >= x[i])
            {
                n -= x[i];
                ++cnt;
            }
            if (!n)
                break;
        }
        printf("%d\n", cnt);
    }
}