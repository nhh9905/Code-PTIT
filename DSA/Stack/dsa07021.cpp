#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		stack<int> st;
		int cnt = 0, ans = 0, idx = -1;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (!st.empty()) {
					st.pop();
					if (!st.empty())
						ans = max(ans, i - st.top());
					else
						ans = max(ans, i - idx);
				}
				else {
					idx = i;
				}
			}
		}

		cout << ans << endl;
	}	

	return 0;
}