#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, m, a[505][505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j])
                    a[i][j] += a[i - 1][j];
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++)
        //         cout << a[i][j] << " ";
        //     cout << endl;
        // }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int minn = a[i][j];

                for (int k = j; k >= 1; k--) {
                    if (a[i][k]) {
                        if (minn > a[i][k])
                            minn = a[i][k];
                        ans = max(ans, minn*(j - k + 1));
                    }
                    else
                        break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}