#include <stdio.h>
#include <math.h>
#define ll long long
int snt(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
void pt(ll n)
{
    int dd = 0;
    ll x = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (x % i == 0) 
        {
            x /= i;
            if (snt(x))
            {
                printf("%lld\n", x);
                dd = 1;
                break;
            }
        }
        if (dd)
            break;
        if (x == 1)
        {
            printf("%d\n", i);
            break;
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        if (snt(n))
            printf("%lld\n", n);
        else
            pt(n);
    }
}