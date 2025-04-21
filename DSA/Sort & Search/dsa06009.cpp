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
		int n, k, ans = 0;
		cin >> n >> k;
		vector<int> a(n);

		for (int &x:a)
			cin >> x;

		sort(a.begin(), a.end());

		for (int i = 0; i < a.size(); i++) {
			int x = k - a[i];
			if (a[i] <= x) {
				vector<int>::iterator l = lower_bound(a.begin() + i + 1, a.end(), x);
				vector<int>::iterator r = upper_bound(a.begin() + i + 1, a.end(), x);
				if (l != r) {
					ans += (r - l);
				}
			}
		}

		cout << ans << endl;
	}	

	return 0;
}