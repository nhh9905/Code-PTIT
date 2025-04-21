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
		bool check = 0;
		vector<int> a(n);

		for (int &x:a)
			cin >> x;

		sort(a.begin(), a.end());

		for (int i = 0; i < a.size() - 1; i++) {
			if (check)
				break;
			for (int j = i + 1; j < a.size(); j++) {
				int sum = a[i] + a[j];
				if (binary_search(a.begin() + j + 1, a.end(), x - sum)) {
					cout << "YES\n";
					check = 1;
					break;
				}
			}
		}

		if (!check)
			cout << "NO\n";
	}	

	return 0;
}