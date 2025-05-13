#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, s;
vector<int> adj[1005];
vector<pii> edge;
bool vis[1005];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	vis[u] = 1;

	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int x:adj[v]) {
			if (!vis[x]) {
				q.push(x);
				vis[x] = 1;
				edge.push_back({v, x});
			}
		}
	}
}

void checkComponent(int u) {
	bfs(u);

	if (edge.size() == n - 1) {
		for (pii x:edge)
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
		cin >> n >> m >> s;
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		checkComponent(s);

		edge.clear();
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		memset(vis, 0, sizeof vis);
	}

	return 0;
}