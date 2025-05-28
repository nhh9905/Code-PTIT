#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[1006];
bool vis[1006];
stack<int> st;

void dfs(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
	st.push(u);
}

void topo() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
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
	}

	topo();

	return 0;
}