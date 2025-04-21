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
		int n, k;
		ll ans = 0;
		cin >> n >> k;
		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n - 1; i++) {
			int pos = upper_bound(a, a + n, k + a[i] - 1) - a;
			// cout << pos << " ";
			ans += (ll)pos - i - 1;
		}
		cout << ans << endl;
	}	

	return 0;
}