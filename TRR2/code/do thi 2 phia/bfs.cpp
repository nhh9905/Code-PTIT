#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, color[1005];
vector<int> adj[1005];

// 0: red, 1: blue
bool bfs(int u) {
	queue<int> q;
	q.push(u);
	color[u] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int x:adj[v]) {
			if (color[x] == -1) {
				q.push(x);
				color[x] = 1 - color[v];
			}
			else if (color[x] == color[v]) // co canh noi
				return 0;
		}
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

	// ktra xem thanh phan lien thong co phai 2 phia ko
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			if (!bfs(i)) {
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