#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n;
		set<int> s;

		for (int i = 1; i <= n; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;
			s.insert(u);
			s.insert(v);
		}

		for (int x:s)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}