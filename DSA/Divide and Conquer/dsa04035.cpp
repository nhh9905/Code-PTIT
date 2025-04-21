#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1e9 + 7;

ll powMod(ll a, ll b) {
	if (b == 0)
		return 1;
	ll tmp = powMod(a, b/2);
	if (b % 2 == 0)
		return (tmp*tmp) % mod;
	return (((tmp*tmp) % mod) * a) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	ll a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		cout << powMod(a, b) << endl;
	}	

	return 0;
}