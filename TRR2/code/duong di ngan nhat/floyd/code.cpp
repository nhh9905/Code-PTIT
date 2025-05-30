#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, q, a[105][105], p[105][105];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][i] = 0;
			if (i != j)
				a[i][j] = 1e9;
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];
				} 
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n >> m;
	init();

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
	}

	floyd();

	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << a[u][v] << endl;
	}

	return 0;
}