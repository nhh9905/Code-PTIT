#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1005];

void sinh(int n) {
	int i = n - 1;
	while (i >= 1 && a[i] > a[i + 1])
		--i;
	if (i == 0) {
		for (int j = 1; j <= n; j++) {
			a[j] = j;
		}
	}
	else {
		int j = n;
		while (a[i] > a[j])
			--j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sinh(n);
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}