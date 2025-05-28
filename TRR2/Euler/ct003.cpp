#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, deg_in[1005], deg_out[1005];
vector<int> adj[1005];
set<int> adj1[1005];
bool vis[1005];

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
	cin.ignore();

	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin >> ws, s);
		stringstream ss(s);
		string tmp;
		vector<string> v;

		while (ss >> tmp) {
			v.push_back(tmp);
		}

		for (int j = 1; j < v.size(); j++) {
			int x = stoi(v[j]);
			adj[i].push_back(x);
			adj[x].push_back(i);
			++deg_out[i], ++deg_in[x];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (abs(deg_out[i] - deg_in[i]) > 1)
			++cnt;
		if (abs(deg_out[i] - deg_in[i]) == 1)
			++cnt1;
	}

	if (cnt)
		cout << "0\n";
	else {
		if (cnt1 == 2)
			cout << "2\n";
		else
			cout << "1\n";
	}
}

void chutrinh(int u) {
	stack<int> st;
	vector<int> EC;
	st.push(u);

	while (!st.empty()) {
		int v = st.top();

		if (!adj1[v].empty()) {
			int k = *adj1[v].begin();
			st.push(k);
			adj1[v].erase(k);
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
		int k;
		cin >> k;

		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			adj1[i].insert(x);
		}
	}

	chutrinh(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	if (t == 1)
		bai1();
	else
		bai2();

	return 0;
}