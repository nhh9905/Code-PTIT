#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105][105];
vector<int> adj[105], joint;
bool vis[105];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	vis[u] = 1;

	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int x:adj[v]) {
			if (!vis[x]) {
				q.push(x);
				vis[x] = 1;
			}
		}
	}
}

void dinhtru() {
	int tplt = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i);
			++tplt;
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		int dem = 0;
		vis[i] = 1;

		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				bfs(j);
				++dem;
			}
		}

		if (dem > tplt)
			joint.push_back(i);
	}

	cout << joint.size() << endl;
	for (int x:joint)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j])
				adj[i].push_back(j);
		}
	}

	dinhtru();

	return 0;
}