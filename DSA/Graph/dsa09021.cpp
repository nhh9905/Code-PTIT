#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("a.inp", "r", stdin);
	int n;
	cin >> n;
	vector<int> adj[n + 5];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x && i < j) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size()) {
			for (int x:adj[i])
				cout << x << " ";
			cout << endl;
		}
	}

	return 0;
}