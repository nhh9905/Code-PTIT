#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("DATA1.in", "r", stdin);
	set<string> st1, st2, st3;
	string s;
	while (cin >> s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		st1.insert(s);
		st3.insert(s);
	}
	cin.clear();
	freopen("DATA2.in", "r", stdin);
	while (cin >> s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		st2.insert(s);
		st3.insert(s);
	}
	cin.clear();
	for (auto x:st3)
		cout << x << " ";
	cout << endl;
	for (auto x:st1) {
		if (st2.count(x))
			cout << x << " ";
	}
}