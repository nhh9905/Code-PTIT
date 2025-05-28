#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, s, t;
vector<int> adj[1005];
bool vis[1005], check = 0;
int par[1005];

bool dfs(int u) {
	vis[u] = 1;
	for (int v:adj[u]) {
		if (!vis[v]) {
			par[v] = u;
			if (dfs(v))
				return 1;
		}
		else if (v != par[u]) {
			s = v, t = u;
			return 1;
		}
	}
	return 0;
}

void path(int s, int t) {
	stack<int> st;

	st.push(s);
	while (s != t) {
		st.push(t);
		t = par[t];
	}
	st.push(s);

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
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (dfs(i)) {
				check = 1;
				path(s, t);
			}
		}
	}

	if (!check)
		cout << "no\n";

	return 0;
}