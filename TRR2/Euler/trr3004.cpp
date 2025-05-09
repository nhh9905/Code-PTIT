#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, a[105][105], deg_in[105], deg_out[105];
bool vis[105];
set<int> adj[105];

void dfs(int u) {
	vis[u] = 1;

	for (int v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}

bool checkComponent() {
	int tplt = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			++tplt;
			dfs(i);
		}
	}

	return tplt == 1;
}

void bai1() {
	int cnt = 0, cnt1 = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j]) {
				++deg_out[i], ++deg_in[j];
				adj[i].insert(j);
				adj[j].insert(i);
			}
		}
	}

	// Do thi lien thong yeu
	if (checkComponent()) {
		for (int i = 1; i <= n; i++) {
			if (deg_in[i] == deg_out[i]) {
				++cnt;
			}
			else {
				if (deg_out[i] - deg_in[i] == 1)
					++cnt1;
				if (deg_in[i] - deg_out[i] == 1)
					++cnt1;
			}
		}

		// Do thi Euler
		if (cnt == n)
			cout << "1\n";
		else {
			// Do thi nua Euler
			if (cnt == n - 2 && cnt1 == 2)
				cout << "2\n";
		}
	}
	// Ko phai Euler
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
		}
		else {
			EC.push_back(v);
			st.pop();
		}
	}

	reverse(begin(EC), end(EC));
	for (int x:EC)
		cout << x << " ";
	cout << endl;
}

void bai2() {
	cin >> n >> u;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j])
				adj[i].insert(j);
		}
	}

	chutrinh(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);

	int t; cin >> t;
	
	if (t == 1)
		bai1();
	else
		bai2();

	return 0;
}