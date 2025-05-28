#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct edge {
	int u, v, w;
} edge;

int n, m;
vector<pii> adj[1005];
bool vis[1005]; // used[i] = 1: i thuoc tap V(MST), 0: i thuoc tap V

void prim(int u) {
	vector<edge> MST;
	int d = 0;
	used[u] = 1;

	while (MST.size() < n - 1) {
		// e = (x, y) la canh ngan nhat voi x thuoc V va y thuoc V(MST)
		int min_w = INT_MAX;
		int X, Y;
		for (int i = 1; i <= n; i++) {
			if (used[i]) {
				for (pii it:adj[i]) {
					int j = it.fi, w = it.se;

					if (!used[j] && w < min_w) {
						min_w = w;
						X = j, Y = i;
					}
				}
			}
		}

		MST.push_back({X, Y, min_w});
		d += min_w;
		used[X] = 1;
	}

	cout << d << endl;
	for (edge it:MST)
		cout << it.u << " " << it.v << " " << it.w << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	memset(vis, 0, sizeof vis);

	prim(1);

	return 0;
}