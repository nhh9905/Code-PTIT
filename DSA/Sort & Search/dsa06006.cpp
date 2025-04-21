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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x:a)
			cin >> x;
		sort(a.begin(), a.end());

		for (int x:a)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}