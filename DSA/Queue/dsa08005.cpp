#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tp(string s) {
	int ans = 0, cnt = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans += (s[i] - '0')*pow(2, cnt);
		++cnt;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		queue<string> q;

		q.push("1");
		while (!q.empty()) {
			int k = tp(q.front());
			// cout << k << " ";
			if (k > n)
				break;
			cout << q.front() << " ";
			q.push(q.front() + "0");
			q.push(q.front() + "1");
			q.pop();
		}
		cout << endl;
	}	

	return 0;
}