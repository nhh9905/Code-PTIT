#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[505][505];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 0;

	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();

		for (int k = 0; k < 8; k++) {
			int i1 = top.first + dx[k], j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1]) {
				q.push({i1, j1});
				a[i1][j1] = 0;
			}
		}
	}
}

void connectComponent() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				++cnt;
				bfs(i, j);
			}
		}
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}

		connectComponent();
	}	

	return 0;
}