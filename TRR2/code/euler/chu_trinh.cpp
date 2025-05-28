#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
set<int> adj[1005];

void euler(int u) {
	stack<int> st;
	vector<int> EC;
	st.push(u);

	while (!st.empty()) {
		int x = st.top();
		if (adj[x].size()) {
			int y = *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else {
			st.pop();
			EC.push_back(x);
		}
	}

	reverse(begin(EC), end(EC));
	for (int v:EC)
		cout << v << " ";
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
		adj[x].insert(y);
		adj[y].insert(x);
	}

	euler(1);

	return 0;
}