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
		int n, cnt = 0, ans = 0;
		cin >> n;
		int a[n], d[1000005] = {0};

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			d[a[i]]++;
			if (d[a[i]] > cnt) {
				cnt = d[a[i]];
				ans = a[i];
			}
		}

		if (cnt > n/2)
			cout << ans << endl;
		else
			cout << "NO\n";
	}	

	return 0;
}