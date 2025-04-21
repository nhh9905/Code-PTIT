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
		int n, m, maxx = 0, minn = 1e9;
		cin >> n >> m;

		while (n--) {
			int x;
			cin >> x;
			maxx = max(maxx, x);
		}

		while (m--) {
			int x;
			cin >> x;
			minn = min(minn, x);
		}

		cout << (ll)maxx*minn << endl;

	}	

	return 0;
}