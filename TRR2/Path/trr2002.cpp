#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, v, a[105][105], len = 0, cnt = 0, par[105];
bool vis[105];
vector<int> adj[105];

void dfs(int s, int t) {
	if (len == 2)
		return;
	vis[s] = 1;

	for (int v:adj[s]) {
		if (!vis[v]) {
			if (v == t && len == 1)
				++cnt;
			else {
				++len;
				dfs(v, t);
				--len;
			}
		}
	}

	vis[u] = 0;
}

void bai1() {
	dfs(u, v);
	cout << cnt << endl;
}

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
				par[x] = v;
			}
		}
	}
}

void duongdi(int s, int t) {
	memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));

    bfs(s);

    if (!vis[t])
        cout << 0;
    else {
        vector<int> path;

        while (t != s) {
            path.push_back(t);
            t = par[t];
        }

        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x:path)
            cout << x << " ";
    }
    cout << endl;
}

void bai2() {
	duongdi(u, v);
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n >> u >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j]) {
				adj[i].push_back(j);
			}
		}
	}

	if (t == 1)
		bai1();
	else
		bai2();

	return 0;
}