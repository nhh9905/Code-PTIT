#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[1005], adj1[1005];
bool vis[1005];
stack<int> st;

void dfs(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
	st.push(u);
}

void dfs1(int u) {
	cout << u << " ";
	vis[u] = 1;
	for (int v:adj1[u]) {
		if (!vis[v])
			dfs1(v);
	}
}

void kosajaru() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}

	int cnt = 0;
	memset(vis, 0, sizeof(vis));

	while (!st.empty()) {
		int v = st.top();
		st.pop();
		if (!vis[v]) {
			dfs1(v);
			++cnt;
			cout << endl;
		}
	}

	cout << cnt << endl;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		adj1[i].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj1[y].push_back(x);
		}

		kosajaru();
	}

	return 0;
}