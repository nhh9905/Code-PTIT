#include <bits/stdc++.h>
#define ll long long
using namespace std;

int count(int b[], int m, int l, int r) {
	auto it1 = lower_bound(b, b + m, l), it2 = upper_bound(b, b + m, r);
	return it2 - it1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		int a[n], b[m];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < m; i++)
			cin >> b[i];
		sort(b, b + m);

		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				ans += count(b, m, 0, 0);
			}
			if (a[i] == 2) {
				ans += m - count(b, m, 2, 4);
			}
			if (a[i] == 3) {
				ans += m - count(b, m, 3, 3);
			}
			if (a[i] >= 4) {
				ans += m - count(b, m, 2, a[i]);
			}
		}
		
		cout << ans << endl;
	}	

	return 0;
}