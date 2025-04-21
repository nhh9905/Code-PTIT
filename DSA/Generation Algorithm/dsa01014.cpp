#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, s, x[1005], cnt = 0;

bool check(int k, int s) {
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += x[i];
	}
	return sum == s;
}

void Try(int n, int k, int s, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			if (check(k, s))
				++cnt;
		}
		else
			Try(n, k, s, i + 1);
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	x[0] = 0;
	while (cin >> n >> k >> s) {
		if (!n && !k && !s)
			return 0;
		Try(n, k, s, 1);
		cout << cnt << endl;
		cnt = 0;
	}	
	return 0;
}