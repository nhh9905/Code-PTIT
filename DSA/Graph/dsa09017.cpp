#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, parent[1005], len[1005], cnt = 0;

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

void Union(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (len[a] < len[b])
			swap(a, b);
		parent[b] = a;
		len[a] += len[b];
		++cnt;
	}
}

void kruskal() {
	cin >> n;
	make_set();
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	if (cnt == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	cnt = 0;
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