#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, m, deg[1005], a[1005][1005];

void bai1() {
    for (int i = 1; i <= n; i++)
        cout << deg[i] << " ";
    cout << endl;
}

void bai2() {
    cout << n << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
        a[u][v] = a[v][u] = 1;
    }

    if (t == 1)
        bai1();
    else
        bai2();

    return 0;
}