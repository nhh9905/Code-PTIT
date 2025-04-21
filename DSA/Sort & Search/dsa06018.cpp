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
		int n, ans = 0;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n - 1; i++) {
			if (a[i] != a[i + 1])
				ans += a[i + 1] - a[i] - 1;
		}
		cout << ans << endl;
	}	

	return 0;
}