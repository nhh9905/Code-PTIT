#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[1005], x[1005];
vector<string> v;

void add(int k) {
	bool check = 1;

	for (int i = 1; i < k; i++) {
		if (a[x[i]] >= a[x[i + 1]]) {
			check = 0;
			break;
		}
	}

	if (check) {
        string tmp;

		for (int i = 1; i <= k; i++) {
            tmp += to_string(a[x[i]]) + " ";
        }
		v.push_back(tmp);
	}
}

void Try(int k, int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			add(k);
		else
			Try(k, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	x[0] = 0;
	for (int i = 2; i <= n; i++) {
		Try(i, 1);
	}

	sort(begin(v), end(v));

	for (string x:v) {
		cout << x << endl;
	}

	return 0;
}