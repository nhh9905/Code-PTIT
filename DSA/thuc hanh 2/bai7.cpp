#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, u, par[1005];
vector<int> adj[1005];
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
				par[x] = v;
			}
		}
	}
}

void path(int s, int t) {
	memset(vis, 0, sizeof vis);

	bfs(s);

	if (!vis[t]) {
		cout << "No path\n";
		return;
	}

	stack<int> st;
	st.push(t);
	while (s != t) {
		t = par[t];
		st.push(t);
	}

	while (!st.empty()) {
		cout << st.top() << " "; st.pop();
	}
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
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			if (i != u)
				path(u, i);
		}
		
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}

	return 0;
}