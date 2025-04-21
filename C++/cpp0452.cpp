#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		map<ll, int> m;
		set<ll> s;
		for (int i = 0; i < n1; i++) {
			ll x;
			cin >> x;
			if (!m[x])
				m[x]++;
		}
		for (int i = 0; i < n2; i++) {
			ll x;
			cin >> x;
			if (m[x] == 1)
				m[x]++;
		}
		for (int i = 0; i < n3; i++) {
			ll x;
			cin >> x;
			if (m[x] == 2)
				s.insert(x);
		}
		if (s.empty()) {
			cout << "-1\n";
			continue;
		}
		for (auto x:s)
			cout << x << " ";
		cout << endl;
	}
}
