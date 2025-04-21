#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	string s;
	vector<int> v;
	while (cin >> s) {
		if (s == "show") {
			if (v.empty())
				cout << "empty\n";
			for (int x:v)
				cout << x << " ";
			cout << endl;
		}
		else if (s == "pop") {
			if (!v.empty())
				v.pop_back();
		}
		else {
			int x;
			cin >> x;
			v.push_back(x);
		}
	}	

	return 0;
}