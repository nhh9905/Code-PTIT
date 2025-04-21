#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, a[1005];
bool ok = 1;
vector<int> v;

void sinh() {
	int i = k, ans = 0;
	while (i >= 1 && a[i] == n - k + i)
		--i;
	if (i == 0) {
		cout << k << endl;
		ok = 0;
	}
	else {
		++a[i];
		if (find(v.begin(), v.end(), a[i]) == v.end())
			++ans;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
			if (find(v.begin(), v.end(), a[j]) == v.end())
				++ans;
		}
		cout << ans << endl;
	}
	v.clear();
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			v.push_back(a[i]);
		}
		ok = 1;
		sinh();
	}
	return 0;
}