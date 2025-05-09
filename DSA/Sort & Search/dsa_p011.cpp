#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, cnt = 0;
char c[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j) {
	c[i][j] = '*';

	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];

		if (c[i1][j1] == '#')
			dfs(i1, j1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == '#') {
				dfs(i, j);
				++cnt;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}