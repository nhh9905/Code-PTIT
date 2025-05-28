#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, in[1005], cnt = 0;
vector<int> adj[1005];

bool kahn() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (!in[i])
			q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		++cnt;
		for (int v:adj[u]) {
			--in[v];
			if (!in[v])
				q.push(v);
		}
	}

	return cnt != n;
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
		++in[y];
	}

	if (kahn())
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}