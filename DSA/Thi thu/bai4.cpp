#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

// Dem so thanh phan lien thong dung DFS
int n, m;
vector<int> adj[100005];
bool vis[100005];

void dfs(int u) {
    vis[u] = 1;

    for (int v:adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

void connectComponent() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++cnt;
            dfs(i);
        }
    }

    cout << cnt << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
    memset(vis, 0, sizeof vis);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    connectComponent();

    return 0;
}