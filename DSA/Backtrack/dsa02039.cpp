#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x[105], cnt;
bool ok = 1;

void sinh() {
	int i = cnt;

	while (i >= 1 && x[i] == 1)
		--i;

	if (i == 0)
		ok = 0;

	else {
		--x[i];
		int d = cnt - i + 1;
		cnt = i;
		int q = d/x[i], r = d % x[i];

		if (q) {
			for (int j = 1; j <= q; j++) {
				++cnt;
				x[cnt] = x[i];
			}
		}

		if (r) {
			++cnt;
			x[cnt] = r;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		vector<vector<int>> vec;
		x[1] = n;
		cnt = 1;
		ok = 1;

		while (ok) {
			vector<int> tmp;
			for (int i = 1; i <= cnt; i++)
				tmp.push_back(x[i]);
			vec.push_back(tmp);
			sinh();
		}

		cout << vec.size() << endl;

		for (vector<int> v:vec) {
			cout << "(";
			for (int i = 0; i < v.size() - 1; i++)
				cout << v[i] << " ";
			cout << *v.rbegin() << ") ";
		}
		cout << endl;
	}	

	return 0;
}