#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
//	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], maxx = -1e7;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > maxx)
				maxx = a[i];
		}
		vector<int> z(maxx + 1, 0);
		for (int i = 0; i < n; i++)
			z[a[i]]++;
		for (int i = 0; i < n; i++) {
			if (a[i] == maxx)
				cout << "_ ";
			else {
				for (int j = a[i] + 1; j <= maxx; j++) {
					if (z[j]) {
						cout << j << " ";
						break;
					}
				}
			}
		}
		cout << endl;
	}
}
