#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n + 1][m + 1] = {};
		a[0][1] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}

		cout << a[n][m] << endl;
	}	

	return 0;
}