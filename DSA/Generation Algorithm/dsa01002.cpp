#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1005];

void sinh(int n, int k) {
	int i = k;
	while (i >= 1 && a[i] == n - k + i)
		--i;
	if (i == 0) {
		for (int i = 1; i <= n; i++)
			a[i] = i;
	}
	else {
		++a[i];
		for (int j = i + 1; j <= k; j++)
			a[j] = a[j - 1] + 1;
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= k; i++)
			cin >> a[i];
		sinh(n, k);
		for (int i = 1; i <= k; i++)
			cout << a[i] << " ";
		cout << endl;
	}	
	return 0;
}