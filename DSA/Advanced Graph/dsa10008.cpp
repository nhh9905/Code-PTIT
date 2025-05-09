#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, u;
vector<pii> adj[1005];

void dijkstra(int s) {
	vector<int> d(n + 1, INT_MAX);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({s, 0});

	while (!q.empty()) {
		pii top = q.top(); q.pop();
		int u = top.fi, len = top.se;

		if (len > d[u])
			continue;

		for (pii it:adj[u]) {
			int v = it.fi, w = it.se;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({v, d[v]});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> m >> u;
		while (m--) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}

		dijkstra(u);

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}

	return 0;
}