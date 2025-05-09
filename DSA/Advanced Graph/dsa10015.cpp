#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

struct edge {
	int u, v, w;
};

int n, m, par[1005], num[1005], ans = 0, cnt = 0;

void init() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		num[i] = 1;
	}
}

int Find(int u) {
	if (u != par[u])
		par[u] = Find(par[u]);
	return par[u];
}

bool Union(int u, int v) {
	int a = Find(u), b = Find(v);

	if (a == b)
		return 0;
	if (num[a] < num[b])
		swap(a, b);

	par[b] = a;
	num[a] += num[b];

	return 1;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		vector<edge> ds;
		cin >> n >> m;
		init();

		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			ds.push_back({u, v, w});
		}

		sort(begin(ds), end(ds), cmp);

		for (edge x:ds) {
			if (Union(x.u, x.v)) {
				++cnt;
				ans += x.w;
			}

			if (cnt == n - 1)
				break;
		}

		cout << ans << endl;

		ans = 0, cnt = 0;
	}

	return 0;
}