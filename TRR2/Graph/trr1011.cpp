#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, cnt = 0, c[105][105];
vector<int> adj[105];
struct edge {
	int x, y, w;
};
typedef struct edge edge;
vector<edge> edges;

void bai1() {
	for (int i = 1; i <= n; i++)
		cout << adj[i].size() << " ";
	cout << endl;
}

void bai2() {
	cout << n << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!c[i][j]) {
				if (i == j)
					cout << "0 ";
				else
					cout << "10000 ";
			}
			else
				cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n >> m;

	memset(c, 0, sizeof(c));
	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back(y);
		adj[y].push_back(x);
		c[x][y] = w;
		c[y][x] = w;
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}