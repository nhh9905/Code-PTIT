#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
		string s;
		getline(cin >> ws, s);

		stringstream ss(s);
		string tmp;
		stack<string> st;

		while (ss >> tmp) {
			st.push(tmp);
		}

		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}	

	return 0;
}