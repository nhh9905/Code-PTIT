#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void duyet(int a[], int n, int i) {
	if (i >= n)
		return;

	duyet(a, n, 2*i + 1);
	cout << a[i] << " ";
	duyet(a, n, 2*i + 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		int a[n + 5];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		duyet(a, n, 0);
		cout << endl;
	}

	return 0;
}