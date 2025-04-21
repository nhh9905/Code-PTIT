#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("a.inp", "r", stdin);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 5);

	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin >> ws, s);
		stringstream ss(s);
		string tmp;
		while (ss >> tmp) {
			int num = (int)stoi(tmp);
			if (i < num)
				adj[i].push_back(num);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size()) {
			sort(adj[i].begin(), adj[i].end());
			for (auto x:adj[i])
				cout << i << " " << x << endl;
		}
	}
	return 0;
}