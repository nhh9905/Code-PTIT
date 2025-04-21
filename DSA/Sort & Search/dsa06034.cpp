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
		int n;
		ll k, ans = 0;
		cin >> n >> k;
		ll a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n - 1; i++) {
			ll pos1 = lower_bound(a + i + 1, a + n, k - a[i]) - a;
			ll pos2 = upper_bound(a + i + 1, a + n, k - a[i]) - a;

			ans += pos2 - pos1;
		}

		cout << ans << endl;
	}	

	return 0;
}