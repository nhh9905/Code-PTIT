#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		set<int> adj[1005];
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].insert(y);
			adj[y].insert(x);
		}

		for (int i = 1; i <= n; i++) {
			if (adj[i].size()) {
				cout << i << ": ";
				for (auto x:adj[i])
					cout << x << " ";
				cout << endl;
			}
		}
	}
	return 0;
}