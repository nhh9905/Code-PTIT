#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1006];
bool visited[1006];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int x:adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = 1;
			}
		}
	}
	cout << endl;
}

int main() {
	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int v, e, t;
		cin >> v >> e >> t;
		while (e--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			memset(visited, 0, sizeof(visited));
		}
		BFS(t);
		for (int i = 1; i <= v; i++)
			adj[i].clear();
	}	
	return 0;
}