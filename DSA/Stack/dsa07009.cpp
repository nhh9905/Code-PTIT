#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

string s;

void xuly(string s) {
	stack<string> st;

	reverse(begin(s), end(s));
	for (char x:s) {
		if (isalpha(x)) {
			string tmp = string(1, x);
			st.push(tmp);
		}
		else {
			string tmp1 = st.top(); st.pop();
			string tmp2 = st.top(); st.pop();
			st.push("(" + tmp1 + x + tmp2 + ")");
		}
	}

	cout << st.top() << endl;
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