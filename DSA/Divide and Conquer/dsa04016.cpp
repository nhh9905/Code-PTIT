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
		int n, m, k;
		cin >> n >> m >> k;
		int a[n + m];

		for (int i = 0; i < n + m; i++)
			cin >> a[i];

		sort(a, a + n + m);
		cout << a[k - 1] << endl;
	}	

	return 0;
}