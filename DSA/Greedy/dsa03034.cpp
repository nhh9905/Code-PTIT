#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n >> m >> k;
		int a[n + 5], b[m + 5], c[k + 5], minn = n;
		vector<int> v;

		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= m; i++)
			cin >> b[i];
		for (int i = 1; i <= k; i++)
			cin >> c[i];

		int i = 1, j = 1, h = 1;
		while (i <= n && j <= m && h <= k) {
			if (a[i] == b[j] && b[j] == c[h]) {
				v.push_back(a[i]);
				++i, ++j, ++h;
			}
			else {
				if (a[i] < b[j])
					++i;
				else {
					if (b[j] < c[h])
						++j;
					else
						++h;
				}
			}
		}

		if (v.empty())
			cout << "NO";
		else {
			for (int x:v)
				cout << x << " ";
		}

		cout << endl;
	}

	return 0;
}