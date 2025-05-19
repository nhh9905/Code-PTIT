#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, q, d[305][305];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            d[i][j] = INT_MAX;
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] == INT_MAX)
            cout << "-1\n";
        else
            cout << d[x][y] << endl;
    }

    return 0;
}