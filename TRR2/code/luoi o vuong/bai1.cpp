// Đếm số thành phần liên thông trên ô lưới
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
char a[105][105];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

// x: có đường đi
void dfs(int i, int j) {
	cout << i << " " << j << endl;
	a[i][j] = 'o';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x')
			dfs(i1, j1);
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'o';
	while (!q.empty()) {
		pair<int, int> top = q.front();
		cout << top.first << " " << top.second << endl;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = top.first + dx[k], j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x') {
				q.push({i1, j1});
				a[i1][j1] = 'o';
			}
		}
	}
}

void connectComponent() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'x') {
				++cnt;
				cout << "Thanh phan lien thong " << cnt << ":\n";
				bfs(i, j);
			}
		}
	}
	cout << cnt << endl;
}

int main() {
	freopen("a.inp", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	
	connectComponent();

	return 0;
}