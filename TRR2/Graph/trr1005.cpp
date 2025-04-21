#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, deg[105];
vector<int> adj[105];

void bai1() {
	for (int i = 1; i <= n; i++) {
		cout << deg[i] << " ";
	}
	cout << endl;
}

void bai2() {
	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << adj[i].size() << " ";
		for (int v:adj[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		++deg[x], ++deg[y];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}