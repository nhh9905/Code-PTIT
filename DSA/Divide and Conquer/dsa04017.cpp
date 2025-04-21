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
		cin >> n;
		ll a[n + 1], b[n];
		bool check = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n - 1; i++) {
			cin >> b[i];
		}

		for (int i = 0; i < n - 1; i++) {
			if (a[i] != b[i]) {
				check = 1;
				cout << i + 1 << endl;
				break;
			}
		}

		if (!check)
			cout << n << endl;
	}	

	return 0;
}