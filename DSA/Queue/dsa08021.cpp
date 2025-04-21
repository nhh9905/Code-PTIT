#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, a[1005][1005], cnt = -1;

struct point {
	int x, y, z;
};

void bfs() {
	queue<point> q;
	q.push({1, 1, 0});

	while (!q.empty()) {
		point v = q.front(); q.pop();

		if (v.x == m && v.y == n) {
			cnt = v.z;
			break;
		}

		if (a[v.x][v.y] == 0)
			continue;
		int j = v.y + a[v.x][v.y], i = v.x + a[v.x][v.y];

		if (j <= n)
			q.push({v.x, j, v.z + 1});
		if (i <= m) 
			q.push({i, v.y, v.z + 1});

		a[v.x][v.y] = 0;
	}

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> m >> n;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}

		bfs();
		cnt = -1;
	}	

	return 0;
}