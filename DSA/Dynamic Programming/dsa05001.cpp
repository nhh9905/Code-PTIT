#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int c[1005][1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		string x, y;
		cin >> x >> y;
		memset(c, 0, sizeof(c));

		for (int i = 1; i <= x.size(); i++) {
			for (int j = 1; j <= y.size(); j++) {
				if (x[i - 1] == y[j - 1])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
					c[i][j] = max(c[i][j - 1], c[i - 1][j]);
			}
		}

		cout << c[x.size()][y.size()] << endl;
	}	

	return 0;
}