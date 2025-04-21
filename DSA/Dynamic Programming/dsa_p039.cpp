#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

/*
1. trang thai da chon
3 1 2 -> 100
1 1 2 -> 101
1 4 2 -> 111

OR: luu -> 100 OR 001 = 101
AND: check -> 100 AND 001 = 0 -> chon

2. dinh nghia dp[i][j]: gia tri lon nhat chon dc cho den hang i trang thai j
*/

int n, a[21][21], dp[21][1 << 21];

int Try(int i, int pre) {
	if (i > n)
		return 0;
	if (dp[i][pre] != -1)
		return dp[i][pre];

	int rowStatus = 1 << (n - 1), x = 0; // toi da 2^(n - 1)
	for (int j = 1; j <= n; j++) {
		if ((pre & rowStatus) == 0) { // hang j chua dc chon
			int current = pre | rowStatus;
			x = max(x, a[i][j] + Try(i + 1, current));
		}
		rowStatus >>= 1;
	}

	dp[i][pre] = x;

	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}

		memset(dp, -1, sizeof(dp));

		cout << Try(1, 0) << endl;
	}

	return 0;
}