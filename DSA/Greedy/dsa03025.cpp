#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
struct point {
	int x, y;
};
typedef struct point point;

bool cmp(point a, point b) {
	return a.y < b.y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		point a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y;

		sort(a + 1, a + 1 + n, cmp);

		int k = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].x >= k) {
				// cout << a[i].x << " " << a[i].y << endl;
				k = a[i].y;
				++cnt;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}

// 19 21
// 32 40
// 51 52
// 65 76