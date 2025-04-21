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
		set<int> s;

		for (int &x:a) {
			cin >> x;
			while (x) {
				s.insert(x % 10);
				x /= 10;
			}
		}

		for (int x:s)
			cout << x << " ";
		cout << endl;
	}	

	return 0;
}