#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
vector<int> adj[1005];
bool vis[1005], ok = 0;
set<int> s;

void dfs(int u) {
    if (ok)
        return;
    
    s.insert(u);
    vis[u] = 1;

    if (u == 2)
        ok = 1;

    for (int v:adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

void dfs1(int u) {
    if (ok)
        return;

    s.insert(u);
    vis[u] = 1;

    if (u == 1)
        ok = 1;

    for (int v:adj[u]) {
        if (!vis[v])
            dfs1(v);
    }
}

void path() {
    dfs(1);

    memset(vis, 0, sizeof vis);
    ok = 0;

    dfs1(2);

    cout << s.size() << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
    memset(vis, 0, sizeof vis);
    ok = 0;
    s.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    int t; cin >> t;
    
    while (t--) {
        cin >> n >> m;

        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        path();
    }

    return 0;
}