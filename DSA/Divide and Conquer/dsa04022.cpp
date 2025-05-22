#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

ll a[30];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	for (int i = 0; i <= 25; i++)
		a[i + 1] = pow(2, i);

	int t; cin >> t;
	
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;

		for (int i = n; i >= 1; i--) {
			if (k == a[i]) {
				cout << char(i + 'A' - 1) << endl;
				break;
			}
			else if (k > a[i])
				k -= a[i];
		}
	}

	return 0;
}