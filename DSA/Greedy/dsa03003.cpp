#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int a[n];
		ll ans = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n; i++) {
			ans += (ll)i*a[i];
			ans %= mod;
		}

		cout << ans << endl;
	}	

	return 0;
}