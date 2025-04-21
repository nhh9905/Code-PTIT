#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);

		for (int &x:a)
			cin >> x;

		if (binary_search(a.begin(), a.end(), x)) {
			auto it = lower_bound(a.begin(), a.end(), x);
			auto it2 = upper_bound(a.begin(), a.end(), x);
			cout << (it2 - a.begin()) - (it - a.begin()) << endl;
		}
		else
			cout << "-1\n";
	}	

	return 0;
}