#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
vector<int> adj[1005];
vector<pii> edges, cau;
bool vis[1005];

void dfs(int u) {
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

void dfs1(int u, int s, int t) {
    vis[u] = 1;

	for (int v:adj[u]) {
        if (v == s && u == t || v == t && u == s)
            continue;

		if (!vis[v])
			dfs1(v, s, t);
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

    for (pii v:edges) {
        memset(vis, 0, sizeof vis);
        int dem = 0;

        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                ++dem;
                dfs1(j, v.fi, v.se);
            }
        }

        if (dem > tplt)
            cau.push_back(v);
    }

    cout << cau.size() << endl;
    for (pii v:cau)
        cout << v.fi << " " << v.se << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            if (x && i < j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                edges.push_back({i, j});
            }
        }
    }

    canhcau();

    return 0;
}