#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105], sum = 0;
bool check = 0;

void Try(int i, int k) {
	if (check)
		return;

	if (2*k == sum) {
		check = 1;
		return;
	}

	if (i < n) {
		if (2*(k + a[i]) <= sum)
			Try(i + 1, k + a[i]);
		Try(i + 1, k);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		sum = 0, check = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		if (sum % 2) {
			cout << "NO\n";
			continue;
		}

		Try(1, 0);

		if (check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}