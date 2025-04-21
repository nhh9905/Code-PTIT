#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		queue<ll> q;
		int cnt = 0;

		q.push(1);
		while (!q.empty()) {
			ll k = q.front();
			// cout << k << " ";
			if (k > n)
				break;
			++cnt;
			q.push(k*10);
			q.push(k*10 + 1);
			q.pop();
		}
		cout << cnt << endl;
	}	

	return 0;
}