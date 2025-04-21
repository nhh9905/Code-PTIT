#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[105][105];

void bai1() {
	int deg[105];

	for (int i = 1; i <= n; i++) {
		deg[i] = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j])
				++deg[i];
		}
		cout << deg[i] << " ";
	}
	cout << endl;
}

void bai2() {
	vector<int> edge[105];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j])
				edge[i].push_back(j);
		}
	}

	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << edge[i].size() << " ";
		for (int v:edge[i])
			cout << v << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);

	int t;
	cin >> t;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}

	if (t == 1)
		bai1();
	else
		bai2();	

	return 0;
}