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
		int n, minn = 1e9;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n - 1; i++) {
			minn = min(minn, a[i + 1] - a[i]);
		}
		cout << minn << endl;
	}	

	return 0;
}