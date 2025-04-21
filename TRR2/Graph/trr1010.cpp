#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, cnt = 0, c[105][105];
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
	cout << n << " " << edges.size() << endl;

	for (edge v:edges)
		cout << v.x << " " << v.y << " " << v.w << endl;
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
			cin >> c[i][j];
			if (c[i][j] > 0 && c[i][j] <= 50 && i < j) {
				adj[i].push_back(j);
				adj[j].push_back(i);
				edges.push_back({i, j, c[i][j]});
			}
		}
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}