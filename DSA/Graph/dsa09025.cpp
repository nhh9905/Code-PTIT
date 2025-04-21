#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj(1005);
int parent[1005];
bool visited[1005];

void DFS(int u) {
	visited[u] = 1;
	for (int x:adj[u]) {
		if (!visited[x]) {
			parent[x] = u;
			DFS(x);
		}
	}
}

void path(int s, int t) {
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));

	DFS(s);

	if (visited[t]) {
		stack<int> path;
		while (t != s) {
			path.push(t);
			t = parent[t];
		}
		path.push(s);
		while (!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
	}
	else
		cout << -1;
	cout << endl;
}

int main() {
	// freopen("a.inp", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int v, e, s, t;
		cin >> v >> e >> s >> t;
		while (e--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}

		path(s, t);

		for (int i = 1; i <= v; i++)
			adj[i].clear();
	}	
	return 0;
}