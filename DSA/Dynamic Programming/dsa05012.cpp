#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k, mod = 1e9 + 7;
ll c[1005][1005];

void tohop() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	tohop();

	while (t--) {
		cin >> n >> k;
		cout << c[n][k] << endl;
	}

	return 0;
}