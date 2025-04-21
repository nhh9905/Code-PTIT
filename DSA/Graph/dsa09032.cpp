#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, ans = 0;
vector<int> adj[100005];
bool visited[100005];

void bfs(int u) {
	int cnt = 1;
	queue<int> q;
	visited[u] = 1;
	q.push(u);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int x:adj[v]) {
			if (!visited[x]) {
				++cnt;
				q.push(x);
				visited[x] = 1;
			}
		}		
	}

	ans = max(ans, cnt);
}

void connectComponent() {
	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}

	cout << ans << endl;

	for (int i = 1; i <= n; i++)
		adj[i].clear();

	ans = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		connectComponent();
	}	

	return 0;
}