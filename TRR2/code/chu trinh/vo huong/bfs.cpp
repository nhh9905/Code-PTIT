#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, par[1005];
vector<int> adj[1005];
bool vis[1005], check = 0;

bool bfs(int u) {
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x:adj[v]) {
			if (!vis[x]) {
				q.push(x);
				vis[x] = 1;
				par[x] = v;
			}
			else if (x != par[v]) {
				return 1;
			}
		}
	}
	return 0;
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

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (bfs(i)) {
				check = 1;
				cout << "yes\n";
				break;
			}
		}
	}

	if (!check)
		cout << "no\n";

	return 0;
}