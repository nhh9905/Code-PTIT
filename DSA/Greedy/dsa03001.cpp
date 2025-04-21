#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, idx = 9, ans = 0;
		cin >> n;

		for (int i = 0; i < 10; i++) {
			if (a[i] > n) {
				idx = i;
				break;
			}
		}

		while (n) {
			if (n >= a[idx]) {
				ans += n/a[idx];
				n -= (n/a[idx])*a[idx];
			}
			--idx;
		}

		cout << ans << endl;
	}	

	return 0;
}