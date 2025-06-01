#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, m, u, v;
vector<int> adj[1005];
bool vis[1005];

void dfs(int u) {
    vis[u] = 1;

    for (int v:adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

void dinhtru() {
    vector<int> tru;

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        dfs(u);

        if (!vis[v]) {
            tru.push_back(i);
        }
    }

    cout << tru.size() << endl;

    for (int x:tru)
        cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    cin >> n >> m >> u >> v;

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dinhtru();

    return 0;
}