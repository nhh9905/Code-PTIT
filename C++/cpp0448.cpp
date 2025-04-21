#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
//	freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, x, cnt = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a == x)
				++cnt;
		}
		if (!cnt)
			cout << "-1\n";
		else
			cout << cnt << endl;
	}
}
