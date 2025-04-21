#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, s, a[205];
bool l[40005]; // neu tao duoc day con a[1]...a[i]

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> s;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		memset(l, 0, sizeof(l));
		l[t] = 0, l[0] = 1;

		for (int i = 1; i <= n; i++) {
			if (l[s])
				break;
			for (int t = s; t >= a[i]; t--) {
				if (!l[t] && l[t - a[i]])
					l[t] = 1;
			}
		}

		if (l[s])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}