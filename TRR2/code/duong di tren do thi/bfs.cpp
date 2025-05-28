#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int par[1005];

void BFS(int u) {
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
		}
	}
}

void path(int s, int t) {
	memset(vis, 0, sizeof(vis));
	memset(par, 0, sizeof(par));

	BFS(s);

	if (!vis[t])
		cout << "Ko co duong di";
	else {
		vector<int> path;
		while (t != s) {
			path.push_back(t);
			t = par[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x:path)
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	freopen("a.inp", "r", stdin);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	path(s, t);
	
	return 0;
}