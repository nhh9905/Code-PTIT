#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x, k, a[105], s = 0, cnt = 0;
bool d[105];

void Try(int i, int sum) {
	for (int j = i; j <= n; j++) {
		if (!d[j]) {
			sum += a[j];
			d[j] = 1;

			if (sum == x) {
				++cnt;
				sum -= a[j];
			}
			else {
				if (sum < x)
					Try(i + 1, sum);
				sum -= a[j];
				d[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> k;

		memset(d, 0, sizeof d);
		s = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
		}

		if (s % k)
			cout << 0;
		else {
			x = s/k;
			Try(1, 0);

			if (cnt == k)
				cout << 1;
			else
				cout << 0;
		}

		cout << endl;
	}

	return 0;
}