#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, in[1006];
vector<int> adj[1006], topo;

void kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!in[i])
			q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo.push_back(u);

		for (int v:adj[u]) {
			--in[v];
			if (!in[v])
				q.push(v);
		}
	}

	for (int x:topo)
		cout << x << " ";
	cout << endl;
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

	kahn();

	return 0;
}