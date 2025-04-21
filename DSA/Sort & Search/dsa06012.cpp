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
		int n, k, a[1005];
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		sort(a + 1, a + 1 + n, greater<int>());

		for (int i = 1; i <= k; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}