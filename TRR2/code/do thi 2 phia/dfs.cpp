#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, color[1005];
vector<int> adj[1005];

// 0: red, 1: blue
bool dfs(int u, int par) {
	color[u] = 1 - color[par];

	for (int v:adj[u]) {
		if (color[v] == -1) {
			if (!dfs(v, u))
				return 0;
		}
		else if (color[v] == color[u])
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	memset(color, -1, sizeof(color));
	bool check = 1;
	color[0] = 1;

	// ktra xem thanh phan lien thong co phai 2 phia ko
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			if (!dfs(i, 0)) {
				check = 0;
				break;
			}
		}
	}

	if (check)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}