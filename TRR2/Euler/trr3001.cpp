#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, a[105][105], deg[105];
set<int> adj[105];
bool vis[105];

void dfs(int u) {
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

void bai1() {
	int tplt = 0, cnt = 0, cnt1 = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] && i < j) {
				adj[i].insert(j);
				adj[j].insert(i);
				++deg[i], ++deg[j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			++tplt;
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (deg[i] % 2 == 0)
			++cnt;
		else
			++cnt1;
	}

	if (tplt == 1) {
		// Do thi Euler
		if (cnt == n)
			cout << "1\n";
		else {
			// Do thi nua Euler
			if (cnt1 == 2)
				cout << "2\n";
		}
	}
	// Ko phai la Euler
	else
		cout << "0\n";
}

void chutrinh(int u) {
	stack<int> st;
	vector<int> EC;
	st.push(u);

	while (!st.empty()) {
		int v = st.top();

		if (!adj[v].empty()) {
			int k = *adj[v].begin();
			st.push(k);
			adj[v].erase(k);
			adj[k].erase(v);
		}
		else {
			EC.push_back(v);
			st.pop();
		}
	}

	reverse(begin(EC), end(EC));
	for (int v:EC)
		cout << v << " ";
	cout << endl;
}

void bai2() {
	cin >> n >> u;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j] && i < j) {
				adj[i].insert(j);
				adj[j].insert(i);
			}
		}
	}

	chutrinh(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);
	// freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);

	int t; cin >> t;
	
	if (t == 1)
		bai1();
	else
		bai2();

	return 0;
}