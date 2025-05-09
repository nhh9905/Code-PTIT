#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

struct point {
	int x, y, dir, turn;
};
typedef struct point point;

int n, m;
char c[505][505];
pii s, t;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[505][505][4];

bool is_valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m && c[i][j] != '*';
}

void bfs(int i, int j) {
	queue<point> q;

	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];

		if (is_valid(i1, j1)) {
			vis[i1][j1][k] = 1;
			q.push({i1, j1, k, 0});
		}
	}

	bool found = 0;
	while (!q.empty()) {
		point v = q.front(); q.pop();

		if (v.x == t.fi && v.y == t.se) {
			found = 1;
			break;
		}

		int dir = v.dir, turn = v.turn;
		for (int k = 0; k < 4; k++) {
			int i1 = v.x + dx[k], j1 = v.y + dy[k], new_turn;

			if (k == dir)
				new_turn = turn;
			else
				new_turn = turn + 1;

			if (new_turn <= 2 && is_valid(i1, j1) && !vis[i1][j1][k]) {
				vis[i1][j1][k] = 1;
				q.push({i1, j1, k, new_turn});
			}
		}
	}

	if (found)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int T; cin >> T;
	
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
				if (c[i][j] == 'S') {
					s = make_pair(i, j);
				}
				if (c[i][j] == 'T') {
					t = make_pair(i, j);
				}
			}
		}

		bfs(s.fi, s.se);

		memset(vis, 0, sizeof(vis));
	}

	return 0;
}