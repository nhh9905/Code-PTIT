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

		cout << "[";
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cout << a[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << "]" << endl;

		for (int i = 0; i < n - 1; i++) {
			cout << "[";
			for (int j = 0; j < n - i - 1; j++) {
				cout << a[j] + a[j + 1];
				a[j] = a[j] + a[j + 1];
				if (j != n - i - 2)
					cout << " ";
			}
			cout << "]" << endl;
		}
	}	

	return 0;
}