#include <bits/stdc++.h>
#define ll long long
using namespace std;

// brute force: dinh tru O(V*(V + E))
// canh cau O(E*(V + E))
// O(V + E)

int n, m;
vector<int> adj[1005];
vector<pair<int, int>> ds;
bool vis[1005];

void dfs(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

void dfs2(int u, int s, int t) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if ((u == s && v == t) || (u == t && v == s)) // loai bo (s, t)
			continue;
		if (!vis[v])
			dfs2(v, s, t);
	}
}

void canhcau() {
	int tplt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			++tplt;
			dfs(i);
		}
	}

	for (pair<int, int> it:ds) {
		int x = it.first, y = it.second;
		// loai bo (x, y) khoi do thi
		memset(vis, 0, sizeof(vis));
		int dem = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				++dem;
				dfs2(j, x, y);
			}
		}
		if (dem > tplt) {
			cout << x << " " << y << endl;
			++ans;
		}
	}

	cout << ans << endl;
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
		ds.push_back({x, y});
	}

	canhcau();

	return 0;
}