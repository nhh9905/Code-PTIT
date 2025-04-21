#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, v, dp[1005][1005];
struct vat {
	int weight, value;
} a[1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> v;

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++)
			cin >> a[i].weight;
		for (int i = 1; i <= n; i++)
			cin >> a[i].value;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= v; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= a[i].weight)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].weight] + a[i].value);
			}
		}

		cout << dp[n][v] << endl;
	}

	return 0;
}