#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
//	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		bool dd = 0;
		int n, res;
		cin >> n;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (m[x]) {
				if (!dd)
					res = x;
				dd = 1;
			}
			m[x]++;
		}
		if (!dd)
			cout << "-1\n";
		else
			cout << res << endl;
	}
}
