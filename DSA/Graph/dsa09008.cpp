#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
	visited[u] = 1;
	for (int v:adj[u]) {
		if (!visited[v])
			dfs(v);
	}
}

void connectComponent(int n) {
	memset(visited, 0, sizeof(visited));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++ans;
			dfs(i);
		}
	}
	cout << ans << endl;
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		connectComponent(n);

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}	
	return 0;
}