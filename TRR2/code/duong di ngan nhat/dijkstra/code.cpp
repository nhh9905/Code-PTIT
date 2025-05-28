#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

// O((V + E)logV)

int n, m, s, t, pre[1005];
vector<pii> adj[1005];
bool vis[1005];

void dijkstra(int s, int t) {
	vector<ll> d(n + 1, INT_MAX);
	d[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s}); // distance, vertex

	while (!q.empty()) {
		pii top = q.top(); q.pop();
		int len = top.fi, u = top.se;

		// if (len > d[u])
		// 	continue;
		if (vis[u])
			continue;
		vis[u] = 1;

		for (pii it:adj[u]) {
			int v = it.fi, w = it.se;

			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
				pre[v] = u;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
	cout << endl;

	cout << d[t] << endl;

	vector<int> path;
	while (t != s) {
		path.push_back(t);
		t = pre[t];
	}

	reverse(begin(path), end(path));
	for (int x:path)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m >> s >> t;
	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		// adj[y].push_back({x, w});
	}

	dijkstra(s, t);

	return 0;
}