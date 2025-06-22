#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, s;
bool vis[1005];
vector<int> adj[1005];
vector<pii> MST;

void dfs(int u) {
    vis[u] = 1;
    for (int v:adj[u]) {
        if (!vis[v]) {
            MST.push_back({min(u, v), max(u, v)});
            dfs(v);
        }
    }
}

void bai1() {
    dfs(s);
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int x:adj[v]) {
            if (!vis[x]) {
                q.push(x);
                vis[x] = 1;
                MST.push_back({min(v, x), max(v, x)});
            }
        }
    }
}

void bai2() {
    bfs(s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int t; cin >> t;

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x)
                adj[i].push_back(j);
        }
    }

    if (t == 1)
        bai1();
    else
        bai2();

    cout << MST.size() << endl;
    for (auto x:MST)
        cout << x.fi << " " << x.se << endl;

    return 0;
}