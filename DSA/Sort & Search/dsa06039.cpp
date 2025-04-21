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
		int n;
		cin >> n;
		int a[n], b[n];
		vector<int> v;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}

		sort(a, a + n);

		for (int i = 0; i < n - 1; i++) {
			int pos = lower_bound(a + i + 1, a + n, a[i]) - a;
			if (a[pos] == a[i]) {
				v.push_back(a[i]);
			}
		}

		if (v.empty())
			cout << "NO\n";
		else {
			for (int i = 0; i < n; i++) {
				if (binary_search(v.begin(), v.end(), b[i])) {
					cout << b[i] << endl;
					break;
				}
			}
		}
	}	

	return 0;
}