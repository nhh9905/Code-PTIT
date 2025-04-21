#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

string s;

int getPriority(char c) {
	if (c == '^')
		return 3;
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

void xuly(string s) {
	vector<char> ans;
	stack<char> st;

	for (char x:s) {
		if (isalpha(x)) {
			ans.push_back(x);
			continue;
		}
		if (x == '(') {
			st.push(x);
			continue;
		}

		if (x == ')') {
			if (!st.empty()) {
				while (!st.empty() && st.top() != '(') {
					ans.push_back(st.top());
					st.pop();
				}
				if (!st.empty())
					st.pop();
			}
			continue;
		}

		if (!st.empty()) {
			while (!st.empty()) {
				if (getPriority(st.top()) >= getPriority(x)) {
					ans.push_back(st.top());
					st.pop();
				}
				else
					break;
			}
			st.push(x);
		}
		else
			st.push(x);
	}

	while (!st.empty()) {
		if (st.top() != '(')
			ans.push_back(st.top());
		st.pop();
	}
	
	for (char x:ans)
		cout << x;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;

	while (t--) {
		cin >> s;
		xuly(s);
	}

	return 0;
}