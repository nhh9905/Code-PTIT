#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, v;
ll ans = -1e18 - 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    scanf("%d%d%d", &n, &u, &v);
    int a[n + 5], idx[n + 5];
    ll sum[n + 5];

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    int truoc = 0, sau = -1;
    for (int i = 1; i <= n; i++) {
        while (truoc <= sau && idx[truoc] < i - v)
            ++truoc;
        
        if (i - u >= 0) {
            while (truoc <= sau && sum[idx[sau]] >= sum[i - u])
                --sau;
            idx[++sau] = i - u;
        }

        if (truoc <= sau)
            ans = max(ans, sum[i] - sum[idx[truoc]]);
    }

    printf("%d", ans);

    return 0;
}