#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll Pow(ll a, ll b) {
	if (b == 0)
		return 1;
	ll tmp = Pow(a, b/2);

	if (b % 2 == 0)
		return (tmp*tmp) % mod;
	return (((tmp*tmp) % mod)*a) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		ll r = 0, x = n;

		while (x > 0) {
			r = r*10 + x % 10;
			x /= 10;
		}

		cout << Pow(n, r) << endl;
	}	

	return 0;
}