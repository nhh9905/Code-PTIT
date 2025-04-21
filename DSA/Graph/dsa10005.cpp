#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, in[1005], out[1005];

void euler() {
	for (int i = 1; i <= n; i++) {
		if (in[i] != out[i]) {
			cout << "0\n";
			return;
		}
	}
	cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
			in[i] = out[i] = 0;

		while (m--) {
			int x, y;
			cin >> x >> y;
			++in[y], ++out[x];
		}

		euler();
	}	

	return 0;
}