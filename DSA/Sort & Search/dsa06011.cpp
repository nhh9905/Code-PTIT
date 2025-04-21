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
		int n, ans = 1e7;
		cin >> n;
		vector<int> a(n);

		for (int &x:a)
			cin >> x;

		sort(a.begin(), a.end());

		int l = 0, r = n - 1;
		
		while (l < r) {
			if (abs(a[l] + a[r]) < abs(ans))
				ans = a[l] + a[r];

			if (a[l] + a[r] < 0) {
				++l;
			}
			else if (a[l] + a[r] > 0) {
				--r;
			}
		}
		cout << ans << endl;
	}	

	return 0;
}