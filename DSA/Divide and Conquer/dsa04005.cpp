#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

ll f[105];

void fibo() {
	f[1] = f[2] = 1;

	for (int i = 3; i < 93; i++)
		f[i] = f[i - 1] + f[i - 2];
}

char find(int n, ll k) {
	if (n == 1)
		return 'A';
	if (n == 2)
		return 'B';
	if (k > f[n - 2])
		return find(n - 1, k - f[n - 2]);
	return find(n - 2, k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	fibo();

	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	}	

	return 0;
}