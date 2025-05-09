#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[1005];
vector<string> v;

void print(int k) {
	for (int i = 1; i <= k; i++)
		cout << v[x[i] - 1] << " ";
	cout << endl;
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;

		if (i == k)
			print(k);
		else
			Try(n, k, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	vector<string>::iterator ip;

	ip = unique(v.begin(), v.end());
	v.resize(distance(v.begin(), ip));

	x[0] = 0;
	Try(v.size(), k, 1);

	return 0;
}