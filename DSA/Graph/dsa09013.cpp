#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[1005];
vector<pair<int, int>> ds;
bool vis[1005];

void dfs(int u) {
    vis[u] = 1;
    for (int v:adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

void dfs2(int u, int s, int t) {
    vis[u] = 1;
    for (int v:adj[u]) {
        if ((u == s && v == t) || (u == t && v == s))
            continue;
        if (!vis[v])
            dfs2(v, s, t);
    }
}

void canhcau() {
    int tplt = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++tplt;
            dfs(i);
        }
    }

    for (pair<int, int> v:ds) {
        int dem = 0;
        int x = v.first, y = v.second;
        memset(vis, 0, sizeof(vis));
        
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                ++dem;
                dfs2(j, x, y);
            }
        }

        if (dem > tplt)
            cout << x << " " << y << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
    ds.clear();
    memset(vis, 0, sizeof(vis));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            ds.push_back({x, y});
        }

        canhcau();
    }

    return 0;
}