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
		int a[n];
		ll num1 = 0, num2 = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				num1 = num1*10 + a[i];
			else
				num2 = num2*10 + a[i];
		}

		cout << num1 + num2 << endl;
	}

	return 0;
}