#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, s, m;
		cin >> n >> s >> m;
		// No Sunday
		int can = m*s, mua = n*(s - s/7);
		if (mua < can)
			cout << -1;
		else {
			for (int i = 1; i <= s - s/7; i++) {
				if (n*i >= can) {
					cout << i;
					break;
				}
			}
		}
		cout << endl;
	}	

	return 0;
}