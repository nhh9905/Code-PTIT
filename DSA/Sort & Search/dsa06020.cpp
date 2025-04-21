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
		int n, x;
		cin >> n >> x;
		int a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		if (binary_search(a + 1, a + 1 + n, x))
			cout << "1\n";
		else
			cout << "-1\n";
	}	

	return 0;
}