#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, in[1005];

void euler() {
	int cnt = 0, cnt1 = 0;

	for (int i = 1; i <= n; i++) {
		if (in[i] % 2)
			++cnt;
		else
			++cnt1;
	}

	if (cnt == 2) {
		cout << "1\n";
		return;
	}

	if (cnt1 == n)
		cout << "2\n";
	else
		cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			++in[x], ++in[y];
		}

		euler();

		for (int i = 1; i <= n; i++) {
			in[i] = 0;
		}
	}

	return 0;
}