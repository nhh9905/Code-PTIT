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
		int n, idx;
		cin >> n;
		ll a[n], minn = 1e18;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < minn) {
				idx = i;
				minn = a[i];
			}
		}

		cout << idx << endl;

	}

	return 0;
}