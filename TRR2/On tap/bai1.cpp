#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, cnt = 0;
vector<int> adj[1005], vec[1005];
bool vis[1005];

void dfs(int u) {
	vec[cnt].push_back(u);
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

void connectComponent() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			++cnt;
			dfs(i);
		}
	}

	cout << cnt << endl;

	for (int i = 1; i <= cnt; i++) {
		sort(begin(vec[i]), end(vec[i]));
		for (int x:vec[i])
			cout << x << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vec[i].clear();
	}
	memset(vis, 0, sizeof vis);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
		
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;

			if (x) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	connectComponent();

	return 0;
}