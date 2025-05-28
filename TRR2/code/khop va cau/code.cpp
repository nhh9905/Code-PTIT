#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, timeDfs = 0, bridge = 0, cntJoint = 0;
int num[105], low[105];
vector<int> adj[105], v;
bool joint[105];

void dfs(int u, int pre) {
	int child = 0;
	num[u] = low[u] = ++timeDfs;

	for (int v:adj[u]) {
		if (v == pre) // neu v da duoc tham
			continue;
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]); // (u, v) la canh net lien va v ko phai cha u

			if (low[v] == num[v])
				++bridge;
			++child;

			if (u == pre) {
				if (child > 1)
					joint[u] = 1;
			}
			else if (low[v] >= num[u])
				joint[u] = 1;
		}
		else
			low[u] = min(low[u], num[v]); // (u, v) la canh net dut
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!num[i])
			dfs(i, i);
	}

	for (int i = 1; i <= n; i++) {
		if (joint[i]) {
			++cntJoint;
			// v.push_back(i);
		}
	}

	cout << cntJoint << " " << bridge << endl;

	return 0;
}