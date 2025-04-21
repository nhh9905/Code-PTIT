#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n, cnt = 0;
	cin >> n;
	vector<int> a, b;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i % 2)
			a.push_back(x);
		else
			b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			cout << a[cnt] << " ";
		}
		else {
			cout << b[cnt] << " ";
			++cnt;
		}
	}

	return 0;
}