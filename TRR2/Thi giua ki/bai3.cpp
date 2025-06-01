#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, m, s;
vector<int> adj[1005];
vector<pii> MST;
bool vis[1005];

void dfs(int u) {
    vis[u] = 1;

    for (int v:adj[u]) {
        if (!vis[v]) {
            MST.push_back({v, u});
            dfs(v);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int x:adj[v]) {
            if (!vis[x]) {
                MST.push_back({x, v});
                q.push(x);
                vis[x] = 1;
            }
        }
    }
}

void bai1() {
    dfs(s);

    for (pii x:MST)
        cout << x.fi << " " << x.se << endl;
}

void bai2() {
    bfs(s);

    for (pii x:MST)
        cout << x.fi << " " << x.se << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    int t; cin >> t;

    cin >> n >> m >> s;

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (t == 1)
        bai1();
    else
        bai2();

    return 0;
}