#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
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
		map<int, int> m;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			++m[x];
		}

		vector<pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), cmp);

		for (pair<int, int> x:v) {
			for (int i = 0; i < x.second; i++)
				cout << x.first << " ";
		}
		cout << endl;
	}	

	return 0;
}