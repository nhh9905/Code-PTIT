#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
vector<int> adj[1005], path;
set<vector<int>> chutrinh;
bool vis[1005];

void dfs(int u, bool passed) {
    vis[u] = 1;
    path.push_back(u);

    if (u == 2)
        passed = 1;

    for (int v:adj[u]) {
        if (v == u && path.size() >= 2 && passed)
            chutrinh.insert(path);
        else if (!vis[v])
            dfs(v, passed);
    }

    vis[u] = 0;
    path.pop_back();
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

        dfs(1, 0);

        for (vector<int> v:chutrinh) {
            for (int x:v)
                cout << x << " ";
            cout << 1 << endl;
        }

        for (int i = 1; i <= n; i++)
            adj[i].clear();
        path.clear();
        for (auto x:chutrinh)
            x.clear();
        memset(vis, 0, sizeof vis);
    }

    return 0;
}