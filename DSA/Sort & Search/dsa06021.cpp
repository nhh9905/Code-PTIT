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
		int n, x, pos = 0;
		cin >> n >> x;
		int a[n + 5];

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == x)
				pos = i;
		}

		cout << pos << endl;
	}

	return 0;
}