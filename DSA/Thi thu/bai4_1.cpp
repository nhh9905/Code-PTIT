#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

// Dem so thanh phan lien thong dung DSU
int n, m, par[1005], num[1005];

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

void Union(int u, int v) {
	int a = Find(u), b = Find(v);

	if (a == b)
		return;

	if (num[a] < num[b])
		swap(a, b);

	par[b] = a;
	num[a] += num[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp", "r", stdin);

    cin >> n >> m;

    init();

    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (Find(i) == i)
            ++cnt;
    }

    cout << cnt << endl;

    return 0;
}