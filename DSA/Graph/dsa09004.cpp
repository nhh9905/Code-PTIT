#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[1005];
vector<int> adj[1005];

void DFS(int u) {
	cout << u << " ";
	visited[u] = 1;
	for (int v:adj[u]) {
		if (!visited[v])
			DFS(v);
	}
}

int main() {
	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int v, e, u;
		cin >> v >> e >> u;
		while (e--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		DFS(u);
		cout << endl;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= v; i++)
			adj[i].clear();
	}
	return 0;
}