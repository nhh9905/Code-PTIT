#include <stdio.h>
#define ll long long
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}
int main()
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        ll ans = 1;
        for (ll i = n; i <= m; i++)
            ans = lcm(ans, i);
        printf("%lld\n", ans);
    }
}