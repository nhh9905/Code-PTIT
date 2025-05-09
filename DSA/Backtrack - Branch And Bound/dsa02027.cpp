#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, c[20][20], x[20], cmin = INT_MAX, ans = INT_MAX, d = 0;
bool vis[20];

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!vis[j]) {
			x[i] = j;
			d += c[x[i - 1]][x[i]];
			vis[j] = 1;

			if (i == n)
				ans = min(ans, d + c[x[n]][1]);
			else if (d + cmin*(n - i + 1) < ans)
				Try(i + 1);

			vis[j] = 0;
			d -= c[x[i - 1]][x[i]];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			cmin = min(cmin, c[i][j]);
		}
	}

	x[1] = 1;
	vis[1] = 1;
	Try(2);

	cout << ans << endl;

	return 0;
}