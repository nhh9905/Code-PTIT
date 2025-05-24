#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, q, a[305][305];

void init() {
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;

        for (int j = 1; j <= n; j++) {
            if (i != j) {
                a[i][j] = 1e9 + 5;
            }
        }
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> m >> q;

    init();

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
    }
    
    floyd();

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (a[u][v] == 1e9 + 5)
            cout << "-1\n";
        else
            cout << a[u][v] << endl;
    }

    return 0;
}