#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
vector<int> adj[10005], adj1[10005];
bool vis[10005];
stack<int> st;

void dfs(int u) {
    vis[u] = 1;

    for (int v:adj[u]) {
        if (!vis[v])
            dfs(v);
    }

    st.push(u);
}

void dfs1(int u) {
    vis[u] = 1;

    for (int v:adj1[u]) {
        if (!vis[v])
            dfs1(v);
    }
}

void korasaju() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }

    memset(vis, 0, sizeof vis);
    int tplt = 0;

    while (!st.empty()) {
        int top = st.top(); st.pop();

        if (!vis[top]) {
            dfs1(top);
            ++tplt;
        }
    }

    cout << tplt << endl;
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
        adj1[v].push_back(u);
    }

    korasaju();

    return 0;
}