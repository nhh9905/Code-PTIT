#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, dem[105]; // dem: dem so ki tu A trong xau f[n]
ll k, f[105];

void fibo() {
	f[0] = f[1] = 1;
	dem[0] = 1, dem[1] = 0;
	for (int i = 2; i < 93; i++) {
		f[i] = f[i - 1] + f[i - 2];
		dem[i] = dem[i - 1] + dem[i - 2];
	}
}

ll countA(int n, ll k) {
	if (k == 0)
		return 0;
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;

	if (k <= f[n - 1])
		return countA(n - 1, k);
	return dem[n - 1] + countA(n - 2, k - f[n - 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	fibo();

	while (t--) {
		cin >> n >> k;
		cout << k - countA(n, k) << endl;
	}	

	return 0;
}