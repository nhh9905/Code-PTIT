#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c;
int k, n, x[1005];

void print(int k) {
	for (int i = 1; i <= k; i++)
		cout << (char)(x[i] + 'A');
	cout << endl;
}

void Try(int i) {
	for (int j = x[i - 1]; j <= n; j++) {
		x[i] = j;
		if (i == k)
			print(k);
		else
			Try(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> c >> k;
	n = c - 'A';

	x[0] = 0;
	Try(1);

	return 0;
}