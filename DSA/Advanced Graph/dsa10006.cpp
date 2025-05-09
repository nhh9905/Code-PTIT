#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, u;
vector<int> adj[1005];
vector<pii> ds;
bool vis[1005];

void dfs(int u) {
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v]) {
			ds.push_back({u, v});
			dfs(v);
		}
	}
}

void connectComponent(int u) {
	dfs(u);

	if (ds.size() == n - 1) {
		for (pii x:ds)
			cout << x.fi << " " << x.se << endl;
	}
	else
		cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> m >> u;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		connectComponent(u);

		memset(vis, 0, sizeof vis);
		ds.clear();
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}

	return 0;
}