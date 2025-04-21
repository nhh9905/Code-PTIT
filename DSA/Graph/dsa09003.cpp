#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		vector<int> adj[1005];
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			cout << i << ": ";
			for (auto x:adj[i])
				cout << x << " ";
			cout << endl;
		}
	}	
	return 0;
}