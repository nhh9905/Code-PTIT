#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, u, a[105][105], x[105], used[105];
vector<vector<int>> vec;

void print() {
	vector<int> tmp;
	for (int i = 1; i <= n; i++)
		tmp.push_back(x[i]);
	tmp.push_back(x[1]);
	vec.push_back(tmp);
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j] && a[x[i - 1]][j]) { // co canh noi x[i - 1], j
			x[i] = j;
			used[j] = 1;

			if (i == n) {
				if (a[x[n]][x[1]]) {
					print();
				}
			}
			else
				Try(i + 1);
			
			used[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);
	// freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);

	cin >> n >> u;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	x[1] = u;
	used[u] = 1;
	Try(2);

	if (vec.empty())
		cout << 0 << endl;
	else {
		for (vector<int> v:vec) {
			for (int x:v)
				cout << x << " ";
			cout << endl;
		}
		cout << vec.size() << endl;
	}

	return 0;
}