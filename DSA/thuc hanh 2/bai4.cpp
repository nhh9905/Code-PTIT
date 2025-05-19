#include <bits/stdc++.h>
#define ll long long
using namespace std;

string check(string &s) {
	string dx = s;
	reverse(begin(dx), end(dx));
	return dx;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		queue<string> q;
		vector<string> v;

		q.push("6");
		q.push("8");
		while (v.size() < n) {
			string s = q.front(); q.pop();
			v.push_back(s + check(s));
			q.push(s + "6");
			q.push(s + "8");
		}

		for (string x:v) {
			cout << x << " ";
		}
		cout << endl;
	}	

	return 0;
}