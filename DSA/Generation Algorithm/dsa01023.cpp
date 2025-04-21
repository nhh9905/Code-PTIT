#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005], x[1005], cnt = 0;

bool check(int a[], int n, int k) {
	for (int i = 1; i <= k; i++) {
		if (a[i] != x[i])
			return 0;
	}
	return 1;
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			++cnt;
			if (check(a, n, k)) {
				cout << cnt << endl;
				return;
			}
		}
		else
			Try(n, k, i + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	x[0] = 0;
	while (t--) {
		cnt = 0;
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= k; i++)
			cin >> a[i];
		Try(n, k, 1);
	}	
	return 0;
}