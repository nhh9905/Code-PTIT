#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

string s;

int getPriority(char c) {
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

void xuly(string s) {
	stack<char> st;
	vector<char> vec;

	reverse(begin(s), end(s));
	for (char x:s) {
		if (isalpha(x)) {
			vec.push_back(x);
			continue;
		}

		if (x == ')') {
			st.push(x);
			continue;
		}

		if (x == '(') {
			while (!st.empty()) {
				if (st.top() != ')') {
					vec.push_back(st.top());
					st.pop();
				}
				else
					break;
			}
			if (!st.empty())
				st.pop();
			continue;
		}

		while (!st.empty() && getPriority(st.top())) {
			if (getPriority(st.top()) > getPriority(x)) {
				vec.push_back(st.top());
				st.pop();
			}
			else
				break;
		}
		st.push(x);
	}

	while (!st.empty()) {
		if (st.top() != ')')
			vec.push_back(st.top());
		st.pop();
	}

	reverse(begin(vec), end(vec));
	for (char x:vec)
		cout << x;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> s;
		xuly(s);
	}

	return 0;
}