#include <bits/stdc++.h>
#define ll long long
using namespace std;

// deg+: out, deg-: in
int n, m, in[1005], out[1005];
set<int> adj[1005];

void euler() {
	int u;
	// Do thi vo huong
	for (int i = 1; i <= n; i++) {
		if (in[i] % 2) {
			u = i;
			break;
		}
	}

	// Do thi co huong
	// for (int i = 1; i <= n; i++) {
	// 	if (out[i] - in[i] == 1) {
	// 		u = i;
	// 		break;
	// 	}
	// }

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
	for (int x:EC)
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
		adj[x].insert(y);
		adj[y].insert(x);
		++in[x], ++in[y];
		
		// ++in[y], ++out[x];
	}

	euler();

	return 0;
}