#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> k;
    ll h[n + 5], dp[n + 5];

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i] = 1e9;
    }

    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= min(i + k, n); j++) {
            dp[j] = min(abs(h[i] - h[j]) + dp[i], dp[j]);
        }
    }

    cout << dp[n];

    return 0;
}