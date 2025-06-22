#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, s, t, par[1005];
vector<pii> adj[1005];

void dijkstra() {
    vector<ll> d(n + 1, INT_MAX);
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s}); // dis, vertex

    while (!q.empty()) {
        pii top = q.top(); q.pop();
        int len = top.fi, u = top.se;

        for (pii x:adj[u]) {
            int v = x.fi, w = x.se;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }

    if (d[t] == INT_MAX) {
        cout << 0;
        return;
    }

    cout << d[t] << endl;
    vector<int> vec;
    while (t != s) {
        vec.push_back(t);
        t = par[t];
    }
    vec.push_back(s);
    reverse(begin(vec), end(vec));
    for (int x:vec)
        cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            if (w > 0 && w <= 50) {
                adj[i].push_back({j, w});
            }
        }
    }

    dijkstra();

    return 0;
}