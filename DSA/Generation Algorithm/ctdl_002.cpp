#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, k, a[1005], x[1005];
vector<vector<int>> v;

void print() {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		if (x[i])
			sum += a[i];
	}

	if (sum == k) {
		vector<int> tmp;

		for (int i = 1; i <= n; i++) {
			if (x[i])
				tmp.push_back(a[i]);
		}

		v.push_back(tmp);
	}
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n)
			print();
		else
			Try(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	Try(1);

	for (vector<int> vec:v) {
		for (int x:vec)
			cout << x << " ";
		cout << endl;
	}

	cout << v.size() << endl;

	return 0;
}