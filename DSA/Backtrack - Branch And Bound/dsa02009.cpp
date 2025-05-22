#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x, k, a[105], s = 0;
bool check = 0;

void Try(int sum, int cnt) {
	if (check)
		return;
	
	if (cnt == k) {
		check = 1;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (sum == x)
			Try(0, cnt + 1);
		else if (sum < x)
			Try(sum + a[i], cnt);
		else
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> k;
		check = 0;
		s = 0;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
		}

		if (s % k)
			cout << 0;
		else {
			x = s/k;
			Try(0, 0);

			cout << check;
		}

		cout << endl;
	}

	return 0;
}