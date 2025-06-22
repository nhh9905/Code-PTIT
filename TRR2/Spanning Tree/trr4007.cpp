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

int n, m, par[1005], num[1005], ans = 0;
edge a[1005];

void init() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        num[i] = 1;
    }
}

int find(int u) {
    if (par[u] != u)
        par[u] = find(par[u]);
    return par[u];
}

bool Union(int u, int v) {
    int a = find(u), b = find(v);

    if (a == b)
        return 0;

    if (num[a] < num[b])
        swap(a, b);
    par[b] = a;
    num[a] += num[b];
    return 1;
}

bool cmp(edge a, edge b) {
    if (a.w == b.w) {
        if (a.u == b.u)
            return a.v < b.v;
        return a.u < b.u;
    }

    return a.w < b.w;
}

void kruskal() {
    sort(a + 1, a + 1 + m, cmp);
    vector<edge> MST;

    for (int i = 1; i <= m; i++) {
        if (MST.size() == n - 1)
            break;

        if (Union(a[i].u, a[i].v)) {
            ans += a[i].w;
            MST.push_back(a[i]);
        }
    }

    cout << ans << endl;
    for (auto x:MST)
        cout << min(x.u, x.v) << " " << max(x.u, x.v) << " " << x.w << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    init();

    kruskal();

    return 0;
}