#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, cnt = 1, ans = 1;

int solve(vector<int> a, vector<int> b) {
    int maxx = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1 && j > 1 && 1ll*a[i - 1]*b[j - 2] == 1ll*a[i - 2]*b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 1;

            maxx = max(maxx, dp[i][j]);
        }
    }
    return maxx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> m;
    vector<int> a(n), b(n);

    for (int &x:a)
        cin >> x;
    for (int &x:b)
        cin >> x;

    cout << solve(a, b);

    return 0;
}