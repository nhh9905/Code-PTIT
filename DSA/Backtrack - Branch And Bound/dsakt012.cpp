#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s, t[1005], x[1005];
bool check = 0;

void in(int k) {
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += t[x[i]];
	}
	if (ans == s && !check) {
		check = 1;
		cout << k << endl;
	}
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			in(k);
		else
			Try(n, k, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
		
	sort(t + 1, t + 1 + n);

	for (int i = 1; i <= n; i++) {
		if (check)
			break;
		Try(n, i, 1);
	}

	if (!check)
		cout << "-1\n";

	return 0;
}