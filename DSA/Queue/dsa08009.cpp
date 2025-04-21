#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int s, t;

int change(int s, int t) {
	int a[2005] = {0};
	queue<int> q;
	q.push(s);

	while (!a[t]) {
		int x = q.front(); q.pop();
		if (x > 1 && !a[x - 1]) {
			a[x - 1] = a[x] + 1;
			q.push(x - 1);
		}
		if (x*2 < 20000 && !a[x*2]) {
			a[x*2] = a[x] + 1;
			q.push(x*2);
		}
	}

	return a[t];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int T;
	cin >> T;

	while (T--) {
		cin >> s >> t;
		cout << change(s, t) << endl;
	}	

	return 0;
}