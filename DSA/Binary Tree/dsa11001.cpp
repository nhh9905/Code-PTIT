#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

void duyet(string s) {
	stack<string> st;
	
	for (char x:s) {
		if (isalpha(x))
			st.push(string(1, x));
		else {
			string tmp1 = st.top(); st.pop();
			string tmp2 = st.top(); st.pop();
			st.push(tmp2 + string(1, x) + tmp1);
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
		string s;
		cin >> s;
		duyet(s);
	}

	return 0;
}