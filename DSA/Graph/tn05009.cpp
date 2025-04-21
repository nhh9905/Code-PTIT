#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
int start, finish, par[1005];
bool visited[1005], check = 0;

bool dfs(int u) {
	visited[u] = 1;
	for (int v:adj[u]) {
		if (!visited[v]) {
			par[v] = u;
			if (dfs(v))
				return 1;
		}
		else if (v != par[u] && v == 1) {
			start = v, finish = u;
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
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		for (int i = 1; i <= n; i++)
			sort(adj[i].begin(), adj[i].end());

		if (dfs(1)) {
			check = 1;
			path(start, finish);
		}

		if (!check)
			cout << "NO\n";

		for (int i = 1; i <= n; i++)
			adj[i].clear();
		memset(visited, 0, sizeof(visited));
		check = 0;
	}

	return 0;
}