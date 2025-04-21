#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, color[1005];
vector<int> adj[1005];

bool dfs(int u) {
	color[u] = 1;
	for (int v:adj[u]) {
		if (!color[v]) {
			if (dfs(v))
				return 1;
		}
		else if (color[v] == 1)
			return 1;
	}
	color[u] = 2;
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
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			if (!color[i]) {
				if (dfs(i)) {
					check = 1;
					cout << "YES\n";
					break;
				}
			}
		}

		if (!check)
			cout << "NO\n";

		memset(color, 0, sizeof(color));
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}	

	return 0;
}