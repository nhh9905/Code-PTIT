#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int par[1005];

void DFS(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v]) {
			par[v] = u;
			DFS(v);
		}
	}
}

void path(int s, int t) {
	memset(vis, 0, sizeof(vis));
	memset(par, 0, sizeof(par));
	DFS(s);
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