#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, parent[1005];
vector<int> adj[1005];
bool visited[1005];

bool dfs(int u) {
	visited[u] = 1;
	for (int v:adj[u]) {
		if (!visited[v]) {
			parent[v] = u;
			if (dfs(v))
				return 1;
		}
		else if (v != parent[u])
			return 1;
	}
	return 0;
}

void chu_trinh() {
	bool check = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i)) {
				check = 1;
				cout << "YES\n";
				break;
			}
		}
	}
	if (!check)
		cout << "NO\n";

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		chu_trinh();
	}

	return 0;
}