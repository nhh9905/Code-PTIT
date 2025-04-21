#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[100005];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		int b[n + 5];

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = i;
		}

		sort(b + 1, b + 1 + n, cmp);

		// for (int i = 1; i <= n; i++) {
		// 	cout << b[i] << " ";
		// }
		// cout << endl;

		int minPos = n + 1, maxDist = -1;
		for (int i = 1; i <= n; i++) {
			maxDist = max(maxDist, b[i] - minPos);
			minPos = min(minPos, b[i]);
		}

		cout << maxDist << endl;
	}

	return 0;
}