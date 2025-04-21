#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n, s;
	cin >> n >> s;

	// 5
	if (n == 1 && s < 10) {
		cout << s << " " << s;
		return 0;
	}

	if (s == 0 || (s > n*9)) {
		cout << "-1 -1";
	}
	else {
		int k = s/9;
		int d = s % 9;

		// 2 18
		if (k == n) {
			for (int i = 1; i <= n; i++)
				cout << 9;
			cout << " ";
			for (int i = 1; i <= n; i++)
				cout << 9;
		}
		else {
			// 5 18: k = 2, d = 0
			// 10089 99000
			if (!d) {
				cout << 1;
	            for (int i = 1; i < n - k; i++)
	                cout << 0;
	            cout << 8;
	            for (int i = 1; i < k; i++)
                	cout << 9;
	            cout << " ";
	            for (int i = 1; i <= k; i++)
	                cout << 9;
	            for (int i = k + 1; i <= n; i++)
	                cout << 0;
			}
			else {
				// 3 19: k = 2, d = 1
				// 199 991
				if (k == n - 1) {
	                cout << d;
	                for (int i = 1; i <= k; i++)
	                    cout << 9;
	            }
	            // 6 20
	            // 100199 992000
	            else {
	                cout << 1;
	                for (int i = 1; i <= n - k - 2; i++)
	                    cout << 0;
	                cout << d - 1;
	                for (int i = 1; i <= k; i++)
	                    cout << 9;
	            }
	            cout << " ";
	            for (int i = 1; i <= k; i++)
	                cout << 9;
	            cout << d;
	            for (int i = k + 1; i < n; i++)
	                cout << 0;
			}
		}
	}

	cout << endl;

	return 0;
}