#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, s;
vector<pii> adj[1005];
bool vis[1005];

typedef struct edge {
    int u, v, w;
} edge;


void prim(int u) {
    vis[u] = 1;
    int ans = 0;
    vector<edge> MST;

    while (MST.size() < n - 1) {
        int min_w = INT_MAX;
        int a, b;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                for (auto it:adj[i]) {
                    int j = it.fi, w = it.se;
                    if (!vis[j] && w < min_w) {
                        min_w = w;
                        a = j, b = i;
                    }
                }
            }
        }

        MST.push_back({min(a, b), max(a, b), min_w});
        ans += min_w;
        vis[a] = 1;
    }

    cout << ans << endl;
    for (auto x:MST)
        cout << x.u << " " << x.v << " " << x.w << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;

            if (w)
                adj[i].push_back({j, w});
        }
    }

    prim(s);

    return 0;
}