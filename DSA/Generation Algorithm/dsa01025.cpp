#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[1005];

void print(int k) {
	for (int i = 1; i <= k; i++) {
		cout << (char)(x[i] + 'A' - 1);
	}
	cout << endl;
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			print(k);
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
		int n, k;
		cin >> n >> k;
		Try(n, k, 1);
	}	
	return 0;
}