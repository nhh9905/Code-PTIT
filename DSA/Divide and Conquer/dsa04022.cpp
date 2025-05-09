#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	string s[26];
	char tmp = 'B';
	int x = 1;
	s[1] = "A";
	for (int i = 2; i <= 25; i++) {
		s[i] = s[i - 1] + tmp + s[i - 1];
		++tmp;
	}

	int t; cin >> t;
	
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;

		cout << s[n][k - 1] << endl;
	}

	return 0;
}