#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n + 5], b[m + 5];
		set<int> s;
		vector<int> v;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		sort(b + 1, b + 1 + m);
		for (int i = 1; i <= m; i++) {
			if (binary_search(a + 1, a + 1 + n, b[i]))
				v.push_back(b[i]);
			s.insert(b[i]);
		}

		for (int x:s)
			cout << x << " ";
		cout << endl;
		for (int x:v)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}