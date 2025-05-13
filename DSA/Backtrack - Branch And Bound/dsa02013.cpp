#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, p, s, a[1005], x[1005], cnt = 0;
bool d[1005];
vector<vector<int>> vec;

void sang() {
	for (int i = 2; i <= 20; i++) {
		if (!d[i]) {
			for (int j = i*i; j <= 400; j += i)
				d[j] = 1;
		}
	}
}

void Try(int i, int sum, vector<int> v) {
	for (int j = x[i - 1] + 1; j <= cnt; j++) {
		x[i] = j;
		sum += a[j];
		v.push_back(a[j]);

		if (sum == s) {
			if (v.size() == n)
				vec.push_back(v);
		}
		else if (sum < s)
			Try(i + 1, sum, v);

		v.pop_back();
		sum -= a[j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;

	sang();
	
	x[0] = 0;
	while (t--) {
		cnt = 0;
		cin >> n >> p >> s;

		for (int i = p + 1; i <= s; i++) {
			if (!d[i]) {
				a[++cnt] = i;
			}
		}

		vector<int> v;
		Try(1, 0, v);

		cout << vec.size() << endl;
		for (vector<int> it:vec) {
			for (int k:it)
				cout << k << ' ';
			cout << endl;
		}
		
		vec.clear();
	}

	return 0;
}