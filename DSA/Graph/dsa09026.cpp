#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x:adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = 1;
				parent[x] = v;
			}
		}
	}
}

void path(int s, int t) {
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));

	BFS(s);

	if (!visited[t])
		cout << -1;
	else {
		vector<int> path;
		while (t != s) {
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x:path)
			cout << x << " ";
	}
	cout << endl;
}

int main() {
	// freopen("a.inp", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		path(s, t);
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
	return 0;
}