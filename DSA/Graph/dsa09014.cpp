#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
int par[1005];
bool visited[1005];

bool dfs(int u) {
	visited[u] = 1;
	for (int v:adj[u]) {
		if (!visited[v]) {
			par[v] = u;
			if (dfs(v))
				return 1;
		}
		else if (v != par[u])
			return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		bool check = 0;
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

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

		for (int i = 1; i <= n; i++)
			adj[i].clear();
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}