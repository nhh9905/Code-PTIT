#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7;

typedef struct matran {
	ll a[3][3] = {};

	void init() {
		a[1][1] = a[2][2] = a[2][1] = 1;
	}

	matran operator * (matran o) {
		matran res;

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
				for (int k = 1; k <= 2; k++) {
					res.a[i][j] += (a[i][k] * o.a[k][j]) % mod;
					res.a[i][j] %= mod;
				}
			}
		}

		return res;
	}
} matran;

ll calc(int n) {
	matran f;
	f.a[1][1] = f.a[1][2] = f.a[2][1] = 1;

	matran res;
	res.init();

	while (n) {
		if (n % 2)
			res = res * f;
		n /= 2;

		f = f * f;
	}

	return res.a[1][2];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		cout << calc(n) << endl;
	}

	return 0;
}