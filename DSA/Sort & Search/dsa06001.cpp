#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[1005];
vector<pair<int, int>> v;

void print(int a[], int n) {
	int l = 1, r = n;

	sort(a + 1, a + 1 + n);

	while (l < r) {
		v.push_back({a[r], a[l]});
		++l, --r;
	}

	for (pair<int, int> x:v)
		cout << x.first << " " << x.second << " ";

	if (l == r)
		cout << a[l];
	cout << endl;

	v.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		print(a, n);
	}

	return 0;
}