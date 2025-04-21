#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check[1000005];

void sang() {
	for (int i = 2; i < sqrt(1e6); i++) {
		if (check[i]) {
			for (int j = i*i; j <= 1e6; j += i)
				check[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	memset(check, 1, sizeof(check));
	sang();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int i = 2;
		bool dd = 0;
		while (i < n - 1) {
			if (check[i] && check[n - i]) {
				cout << i << " " << n - i << endl;
				dd = 1;
				break;
			}
			++i;
		}

		if (!dd)
			cout << "-1\n";
	}	

	return 0;
}