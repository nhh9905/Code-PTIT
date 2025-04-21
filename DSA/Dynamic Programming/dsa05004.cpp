#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005], l[1005], ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i]) {
				l[i] = max(l[i], l[j] + 1);
				ans = max(ans, l[i]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}