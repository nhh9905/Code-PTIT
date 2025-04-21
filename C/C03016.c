#include <stdio.h>
#define ll long long
ll f[1005];
void fibo()
{
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= 1000; i++) 
        f[i] = f[i - 1] + f[i - 2];
}
int main()
{
    fibo();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        for (int i = 0; i <= 1000; i++)
        {
            if (f[i] == n) 
            {
                printf("YES\n");
                break;
            }
            else
            {
                if (f[i] > n)
                {
                    printf("NO\n");
                    break;
                }
            }
        }
    }
}