#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105][105], low[105], num[105], timeDfs = 0, bridge = 0;
vector<int> adj[105], joint;
bool checkJoint[105];

void dfs(int u, int pre) {
	int child = 0;
	num[u] = low[u] = ++timeDfs;

	for (int v:adj[u]) {
		if (v == pre)
			continue;
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if (low[v] == num[v])
				++bridge;
			++child;

			if (u == pre) {
				if (child > 1)
					checkJoint[u] = 1;
			}
			else if (low[v] >= num[u])
				checkJoint[u] = 1;
		}
		else
			low[u] = min(low[u], num[v]);
	}
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

	for (int i = 1; i <= n; i++) {
		if (!num[i])
			dfs(i, i);
	}

	for (int i = 1; i <= n; i++) {
		if (checkJoint[i])
			joint.push_back(i);
	}

	cout << joint.size() << endl;
	for (int v:joint)
		cout << v << " ";
	cout << endl;

	return 0;
}