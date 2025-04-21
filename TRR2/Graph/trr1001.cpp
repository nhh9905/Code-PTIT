#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105][105];
vector<int> adj[105];
vector<pii> edge;

void bai1() {
	for (int i = 1; i <= n; i++) {
		int deg = 0;

		for (int j = 1; j <= n; j++)
			deg += a[i][j];

		cout << deg << " ";
	}
	cout << endl;
}

void bai2() {
	cout << n << " " << edge.size() << endl;

	for (pii v:edge)
		cout << v.fi << " " << v.se << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j] && i < j)
				edge.push_back({i, j});
		}
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}