#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, parent[1005], len[1005];

void make_set() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		len[i] = 1;
	}
}

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

bool Union(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (len[a] < len[b])
			swap(a, b);
		parent[b] = a;
		len[a] += len[b];
		return 0;
	}
	else
		return 1;
}

void kruskal() {
	bool check = 0;
	cin >> n >> m;
	make_set();
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (Union(x, y))
			check = 1;
	}
	if (check)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		kruskal();
	}

	return 0;
}