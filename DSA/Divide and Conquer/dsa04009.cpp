#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7;

typedef struct matran {
	ll x[15][15] = {};
	int num;

	void init() {
		for (int i = 1; i <= num; i++)
			x[i][i] = 1;
	}

	matran operator * (matran o) {
		matran res;
		res.num = num;

		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				for (int k = 1; k <= num; k++) {
					res.x[i][j] += (x[i][k] * o.x[k][j]) % mod;
					res.x[i][j] %= mod;
				}
			}
		}

		return res;
	}
} matran;
matran a;

void print(matran a, int k) {
	matran res;
	res.num = a.num;
	res.init();

	while (k) {
		if (k % 2)
			res = res * a;

		k /= 2;

		a = a * a;
	}

	for (int i = 1; i <= res.num; i++) {
		for (int j = 1; j <= res.num; j++)
			cout << res.x[i][j] << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;

		a.num = n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a.x[i][j];
		}

		print(a, k);
	}

	return 0;
}