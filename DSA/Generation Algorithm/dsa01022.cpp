#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1005], x[1005], cnt = 0;
bool used[1005];

bool check(int n) {
	for (int i = 1; i <= n; i++) {
		if (x[i] != a[i])
			return 0;
	}
	return 1;
}

void Try(int n, int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n) {
				++cnt;
				if (check(n)) {
					cout << cnt << endl;
					return;
				}
			}
			else
				Try(n, i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(used, 0, sizeof(used));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		Try(n, 1);
	}
	return 0;
}