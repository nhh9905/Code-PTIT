// Kiểm tra đường đi giữa 2 điểm trên lưới
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, s, t, u, v;
char a[105][105];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int d[105][105]; // luu so buoc di tu o bat dau toi (i, j)

// o: có đường đi, x: ko có đường đi
bool dfs(int i, int j) {
	if (a[i][j] == 'B')
		return 1;
	a[i][j] = 'x';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
			if (dfs(i1, j1))
				return 1;
		}
	}
	return 0;
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'x';
	d[i][j] = 0;
	while (!q.empty()) {
		pair<int, int> top = q.front();
		cout << top.first << " " << top.second << endl;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = top.first + dx[k], j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
				d[i1][j1] = d[top.first][top.second] + 1;
				if (a[i1][j1] == 'B')
					return;
				q.push({i1, j1});
				a[i1][j1] = 'x';
			}
		}
	}
}

int main() {
	freopen("a.inp", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'A') {
				s = i, t = j;
			}
			if (a[i][j] == 'B') {
				u = i, v = j;
			}
		}
	}
	
	bfs(s, t);

	if (!d[u][v])
		cout << "Ko co duong di\n";
	else
		cout << d[u][v] << endl;

	return 0;
}