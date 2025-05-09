#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[1005];
string s;
vector<string> v;

void add(int k) {
	string tmp = "";

	for (int i = 1; i <= k; i++) {
		tmp += s[x[i] - 1];
	}

	v.push_back(tmp);
}

void Try(int n, int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;

		if (i == k)
			add(k);
		else
			Try(n, k, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n >> s;

		for (int i = 1; i <= n; i++)
			Try(n, i, 1);

		sort(begin(v), end(v));

		for (string x:v)
			cout << x << " ";
		cout << endl;

		v.clear();
	}	

	return 0;
}