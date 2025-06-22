#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

typedef struct edge {
    int u, v, w;
} edge;
vector<edge> vec;

int n, s, t, par[1005];

void Bellman_Ford(int s) {
    vector<ll> d(n + 1, INT_MAX);
    d[s] = 0;
    par[s] = -1;

    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w]:vec) {
            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
            }
        }
    }

    for (auto [u, v, w]:vec) {
        if (d[u] != INT_MAX && d[v] > d[u] + w) {
            cout << -1;
            return;
        }
    }

    if (d[t] == INT_MAX) {
        cout << 0;
        return;
    }

    cout << d[t] << endl;
    
    vector<int> vec;
    while (s != t) {
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
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;

            if (abs(w) > 0 && abs(w) <= 50)
                vec.push_back({i, j, w});
        }
    }

    Bellman_Ford(s);

    return 0;
}