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
		int n, l, r;
		cin >> n;
		vector<int> a(n), b(n);

		for (int &x:a)
			cin >> x;

		for (int i = 0; i < n; i++)
			b[i] = a[i];

		sort(a.begin(), a.end());

		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				l = i + 1;
				break;
			}
		}
		
		for (int i = n - 1; i > 0; i--) {
			if (a[i] != b[i]) {
				r = i + 1;
				break;
			}
		}
		cout << l << " " << r << endl;
	}

	return 0;
}