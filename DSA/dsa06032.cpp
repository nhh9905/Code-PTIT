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
		ll a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		sort(a + 1, a + 1 + n);

		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ll target = k - a[i] - a[j];
				int pos = lower_bound(a + j + 1, a + 1 + n, target) - a;
				// cout << pos << " ";

				ans += pos - j - 1;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}