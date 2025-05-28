#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
int color[1005];

// 0: white; 1: grey; 2: black
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
	freopen("a.inp", "r", stdin);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			if (dfs(i)) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";

	return 0;
}