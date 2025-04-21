#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll powMod(int a, int b) {
	if (b == 0)
		return 1;
	ll tmp = powMod(a, b/2);
	if (b % 2 == 0)
		return (tmp*tmp);
	return tmp*tmp*a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		ll a[n + 5];

		for (int i = 1; i <= n; i++)
			a[i] = powMod(2, i - 1);

		for (int i = n; i >= 1; i--) {
			if (a[i] == k) {
				cout << i << endl;
				break;
			}
			else if (k > a[i])
				k -= a[i];
		}
	}	

	return 0;
}