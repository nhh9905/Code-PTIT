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
		vector<int> v[15];
		int n, cnt = 0;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			v[cnt].push_back(a[i]);
		}

		for (int i = 0; i < n - 1; i++) {
			++cnt;
			for (int j = 0; j < n - i - 1; j++) {
				v[cnt].push_back(a[j] + a[j + 1]);
				a[j] = a[j] + a[j + 1];
			}
		}

		for (int i = cnt; i >= 0; i--) {
			cout << "[";
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j];
				if (j != v[i].size() - 1)
					cout << " ";
			}
			cout << "] ";
		}
		cout << endl;
	}	

	return 0;
}