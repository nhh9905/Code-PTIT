#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, x, pos = 0;
		cin >> n >> x;
		int a[n + 5];

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i - 1] > a[i])
				pos = i;
		}

		if (!pos)
			cout << *lower_bound(a + 1, a + 1 + n, x) << endl;

		else {
			int *it = lower_bound(a + 1, a + pos, x);
			if (a[*it] == x)
				cout << *it << endl;

			else {
				*it = lower_bound(a + pos, a + 1 + n, x);
				cout << a[*it] << " " << *it << endl;
			}
		}
	}

	return 0;
}