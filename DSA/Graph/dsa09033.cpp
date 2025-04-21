#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> adj[100005];

bool check() {
	for (int u = 1; u <= n; u++) {
		for (int v:adj[u]) {
			if (adj[u].size() != adj[v].size())
				return 0;
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}	

	return 0;
}