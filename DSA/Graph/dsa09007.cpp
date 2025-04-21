#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x:adj[v]) {
			if (!visited[x]) {
				parent[x] = v;
				q.push(x);
				visited[x] = 1;
			}
		}
	}
}

void Path(int s, int t) {
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	stack<int> path;

	bfs(s);

	while (s != t) {
		path.push(t);
		t = parent[t];
	}
	path.push(t);

	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
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
			adj[y].push_back(x);
		}

		Path(s, t);

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
	return 0;
}