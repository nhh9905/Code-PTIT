#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct edge {
	int u, v, w;
} edge;

int n, m, d[1005], par[1005];
vector<pii> adj[1005];
bool used[1005]; // used[i] = 1: trong MST, 0: thuoc tap V

void prim(int u) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	vector<edge> mst;
	int ans = 0;
	q.push({0, u});

	while (!q.empty()) {
		// e(x, y): canh ngan nhat voi x thuoc V va y thuoc V(MST)
		pii top = q.top(); q.pop();
		int v = top.se, w = top.fi;

		if (used[v])
			continue;

		ans += w;
		used[v] = 1;

		if (u != v)
			mst.push_back({v, par[v], w});

		for (pii it:adj[v]) {
			int y = it.fi, w = it.se;

			if (!used[y] && w < d[y]) {
				q.push({w, y});
				d[y] = w;
				par[y] = v;
			}
		}
	}

	cout << ans << endl;

	for (edge it:mst)
		cout << it.u << " " << it.v << " " << it.w << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	memset(used, 0, sizeof used);
	for (int i = 1; i <= n; i++)
		d[i] = 1e9;

	prim(1);

	return 0;
}