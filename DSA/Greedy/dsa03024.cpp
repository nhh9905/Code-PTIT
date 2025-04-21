#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n;

bool cmp(pii a, pii b) {
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		pii a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y;

		sort(a + 1, a + 1 + n, cmp);
		int idx = 1, cnt = 1;

		for (int i = 2; i <= n; i++) {
			if (a[i].x >= a[idx].y) {
				idx = i;
				++cnt;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}