#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		vector<int> adj[1005];
		set<int> s;
		bool check = 0;

		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			s.insert(y);
		}

		for (int x:s) {
			if (adj[x].size()) {
				check = 1;
				cout << "NO\n";
				break;
			}
		}

		if (!check)
			cout << "YES\n";

		for (int i = 1; i <= n; i++)
			adj[i].clear();
		s.clear();
	}
	return 0;
}