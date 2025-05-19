#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 100005;

bool vis[N];
vector<int> adj[N];
int n, depth = 0;

void dfs(int u, int cnt) {
	vis[u] = 1;
	depth = max(depth, cnt);

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1, 0);

		cout << depth << endl;
		depth = 0;

		for (int i = 1; i <= n; i++)
			adj[i].clear();
		memset(vis, 0, sizeof vis);
	}

	return 0;
}