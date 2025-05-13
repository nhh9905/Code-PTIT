#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x, a[25];
vector<vector<int>> vec;

void Try(int i, int sum, vector<int> v) {
	for (int j = i; j <= n; j++) {
		sum += a[j];
		v.push_back(a[j]);

		if (sum == x)
			vec.push_back(v);
		else {
			if (sum < x)
				Try(j, sum, v);
		}

		v.pop_back();
		sum -= a[j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> x;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);

		vector<int> v;
		Try(1, 0, v);

		if (vec.empty())
			cout << -1;
		else {
			cout << vec.size() << " ";
			for (vector<int> it:vec) {
				cout << "{";
				for (int j = 0; j < it.size() - 1; j++)
					cout << it[j] << " ";
				cout << *it.rbegin() << "} ";
			}
		}

		cout << endl;

		vec.clear();
	}

	return 0;
}