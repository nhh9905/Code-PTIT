#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(int a[], int n, int x) {
	vector<pair<int, int>> v(n);
	v.clear();

	for (int i = 1; i <= n; i++)
		v.push_back(make_pair(abs(a[i] - x), i));

	sort(v.begin(), v.end());

	for (pair<int, int> x:v)
		cout << a[x.second] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n + 5];

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		print(a, n, x);
	}

	return 0;
}