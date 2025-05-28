#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[1005];
bool vis[1005];

void dfs(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

void dinhtru() {
	int ans = 0, tplt = 0;
	memset(vis, 0, sizeof(vis));

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			++tplt;
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1; // loai bo dinh i khoi do thi
		int dem = 0; // dem so tplt sau khi loai bo dinh i
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				++dem;
				dfs(j);
			}
		}
		if (dem > tplt) {
			cout << i << " ";
			++ans;
		}
	}
	cout << endl << ans << endl;
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

	dinhtru();

	return 0;
}