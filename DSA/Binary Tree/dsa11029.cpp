#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
vector<int> adj[1005];
bool vis[1005];
vector<vector<int>> path;

void dfs(int u, vector<int> vec) {
	vis[u] = 1;
	vec.push_back(u);

	if (adj[u].empty())
		path.push_back(vec);

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v, vec);
	}
}

bool cmp(vector<int> a, vector<int> b) {
	return a[a.size() - 1] < b[b.size() - 1];
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
		}

		vector<int> v;
		dfs(1, v);

		sort(begin(path), end(path), cmp);

		for (vector<int> it:path) {
			for (int x:it)
				cout << x << " ";
			cout << endl;
		}

		for (int i = 1; i <= n; i++)
			adj[i].clear();
		memset(vis, 0, sizeof vis);
		path.clear();
	}

	return 0;
}