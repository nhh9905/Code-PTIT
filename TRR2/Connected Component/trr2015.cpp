#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105][105];
bool vis[105];
vector<int> adj[105], adj1[105], adj2[105];
stack<int> st;

void dfs(int u) {
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
	st.push(u);
}

void dfs1(int u, vector<int> vec[]) {
	vis[u] = 1;

	for (int v:vec[u]) {
		if (!vis[v]) {
			dfs1(v, vec);
		}
	}
}

void kosaraju() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}

	int cnt = 0;
	memset(vis, 0, sizeof(vis));

	while (!st.empty()) {
		int v = st.top(); st.pop();
		if (!vis[v]) {
			dfs1(v, adj1);
			++cnt;
		}
	}

	if (cnt == 1)
		cout << "1\n";
	else {
		cnt = 0;
		memset(vis, 0, sizeof(vis));

		// Do thi vo huong tuong ung lien thong -> lien thong yeu
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				++cnt;
				dfs1(i, adj2);
			}
		}

		if (cnt == 1)
			cout << "2\n";
		else
			cout << "0\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	// freopen("a.inp", "r", stdin);
	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j]) {
				adj[i].push_back(j);
				adj1[j].push_back(i);
				adj2[i].push_back(j);
				adj2[j].push_back(i);
			}
		}
	}

	kosaraju();

	return 0;
}