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
		int n, minn = 1e9, minn2 = 1e9;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < minn) {
				minn2 = minn;
				minn = a[i];
			}
			if (a[i] < minn2 && minn != a[i])
				minn2 = a[i];
		}

		if (minn2 != 1e9)
			cout << minn << " " << minn2 << endl;
		else
			cout << "-1\n";
	}	

	return 0;
}