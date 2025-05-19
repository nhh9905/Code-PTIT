#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

stack<string> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	for (int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		string str = "", ans = "";
		st.push("1");

		int x = 2;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'I')
				st.push(to_string(x++));
			else {
				string tmp = st.top(); st.pop();
				tmp = to_string(x++) + tmp;
				st.push(tmp);
			}
		}

		while (!st.empty()) {
			ans = st.top() + ans;
			st.pop();
		}

		cout << "Test " << i << ": " << ans << endl;
	}

	return 0;
}