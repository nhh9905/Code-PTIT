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
		int n, k;
		cin >> n >> k;
		int a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		for (int i = 1; i <= n - k + 1; i++) {
			int maxx = a[i];
			for (int j = i + 1; j <= i + k - 1; j++) {
				maxx = max(maxx, a[j]);
			}
			cout << maxx << " ";
		}
		cout << endl;
	}	

	return 0;
}