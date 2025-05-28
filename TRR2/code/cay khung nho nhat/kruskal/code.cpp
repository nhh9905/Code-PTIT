#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct edge {
	int u, v, w;
} edge;

edge a[1005];
int n, m, parent[1005], len[1005], ans = 0;

void nhap(edge &x) {
	cin >> x.u >> x.v >> x.w;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void init() {
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
		return 1;
	}
	return 0;
}

void kruskal() {
	vector<edge> mst;

	sort(a, a + m, cmp);

	for (int i = 0; i < m; i++) {
		if (mst.size() == n - 1)
			break;
		if (Union(a[i].u, a[i].v)) {
			ans += a[i].w;
			mst.push_back(a[i]);
		}
	}

	if (mst.size() != n - 1)
		cout << "Do thi khong lien thong\n";
	else {
		cout << "MST: " << ans << endl;
		for (edge x:mst)
			cout << x.u << " " << x.v << " " << x.w << endl;
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m;
	init();

	for (int i = 0; i < m; i++)
		nhap(a[i]);

	kruskal();

	return 0;
}