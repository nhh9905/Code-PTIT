#include <bits/stdc++.h>

using namespace std;

struct edge {
    int x, y, w;
};
int n, m;
vector<edge> edges;
int d[1005], par[1005];

void Bellman_Ford(int s) {
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    d[s] = 0;

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w]:edges) {
            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ": ";

        int t = i;
        vector<int> vec;
        while (t != s) {
            vec.push_back(t);
            t = par[t];
        }
        vec.push_back(s);

        reverse(begin(vec), end(vec));

        for (int x:vec)
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> m;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    Bellman_Ford(1);
    return 0;
}