#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(string s) {
	stack<char> st;

	for (char x:s) {
		if (x == '(' || x == '[' || x == '{')
			st.push(x);
		else {
			if (st.empty())
				return 0;
			if (x == ')') {
				if (st.top() != '(')
					return 0;
				else
					st.pop();
			}
			if (x == ']') {
				if (st.top() != '[')
					return 0;
				else
					st.pop();
			}
			if (x == '}') {
				if (st.top() != '{')
					return 0;
				else
					st.pop();
			}
		}
	}

	if (!st.empty())
		return 0;

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (check(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}	

	return 0;
}