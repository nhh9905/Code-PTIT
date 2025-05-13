#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x, a[25];
bool ok = 0;

void print(vector<int> v) {
	cout << "[";
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i] << " ";
	cout << *v.rbegin() << "]";
}

void Try(int i, int sum, vector<int> v) {
	for (int j = i; j <= n; j++) {
		sum += a[j];
		v.push_back(a[j]);

		if (sum == x) {
			ok = 1;
			print(v);
		}
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
		ok = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);

		vector<int> v;
		Try(1, 0, v);

		if (!ok)
			cout << -1;

		cout << endl;
	}

	return 0;
}