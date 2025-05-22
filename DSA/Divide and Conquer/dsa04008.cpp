#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7;

typedef struct matran {
	ll f[3][3] = {};

	void init() {
		f[1][1] = f[1][2] = f[2][1] = 1;
	}

	matran operator * (matran o) {
		matran res;

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
				for (int k = 1; k <= 2; k++) {
					res.f[i][j] += (f[i][k] * o.f[k][j]) % mod;
					res.f[i][j] %= mod;
				}
			}
		}

		return res;
	}
} matran;

ll calc(int n) {
	matran res, a;
	res.init();
	a.init();

	while (n) {
		if (n % 2)
			res = res * a;

		n /= 2;

		a = a * a;
	}

	return res.f[1][2];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		cout << calc(n - 1) << endl;
	}

	return 0;
}