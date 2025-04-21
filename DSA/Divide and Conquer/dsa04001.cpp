#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1e9 + 7;

ll Pow(int n, int k) {
	if (k == 0)
		return 1;
	ll tmp = Pow(n, k/2);
	if (k % 2 == 0)
		return (tmp*tmp) % mod;
	else
		return ((tmp*tmp) % mod)*n % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << Pow(n, k) << endl;
	}	

	return 0;
}