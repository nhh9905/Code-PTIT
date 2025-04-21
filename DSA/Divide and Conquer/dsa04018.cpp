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
		int n, ans = 0;
		bool check = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 1 && !check) {
				check = 1;
				ans = i;
			}
		}
		if (check)
			cout << ans << endl;
		else
			cout << n << endl;
	}

	return 0;
}