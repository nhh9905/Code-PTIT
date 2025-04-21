#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj(1005);
bool visited[1005], check = 0;

void bfs(int u, int t) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x:adj[v]) {
			if (x == t) {
				check = 1;
				return;
			}
			if (!visited[x]) {
				q.push(x);
				visited[x] = 1;
			}
		}
	}
}

void connectComponent(int s, int t) {
	memset(visited, 0, sizeof(visited));
	bfs(s, t);
	if (check == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	check = 0;
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

		int q;
		cin >> q;
		while (q--) {
			int s, t;
			cin >> s >> t;
			connectComponent(s, t);
		}

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}	
	return 0;
}