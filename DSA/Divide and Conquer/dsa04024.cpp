#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7;

typedef struct matran {
	ll x[15][15] = {};
	int n;

	void init() {
		for (int i = 1; i <= n; i++) {
			x[i][i] = 1;
		}
	}

	matran operator * (matran o) {
		matran res;
		res.n = n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					res.x[i][j] += (x[i][k] * o.x[k][j]) % mod;
					res.x[i][j] %= mod;
				}
			}
		}

		return res;
	}
} matran;
matran a;

ll calc(matran a, int k) {
	matran res;
	res.n = a.n;

	res.init();

	while (k) {
		if (k % 2)
			res = res * a;
		k /= 2;

		a = a * a;
	}

	ll ans = 0;
	for (int i = 1; i <= res.n; i++)
		ans = (ans + res.x[i][res.n]) % mod;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		a.n = n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a.x[i][j];
		}

		cout << calc(a, k) << endl;
	}

	return 0;
}