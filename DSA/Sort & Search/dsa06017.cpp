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
		int n, m;
		cin >> n >> m;
		int a[n + m];
		for (int i = 0; i < n + m; i++)
			cin >> a[i];

		sort(a, a + n + m);

		for (int i = 0; i < n + m; i++)
			cout << a[i] << " ";
		cout << endl;
	}	

	return 0;
}