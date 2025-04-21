#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;
	stack<int> st;
	while (t--) {
		string s;
		cin >> s;
		if (s == "POP") {
			if (!st.empty())
				st.pop();
		}
		else if (s == "PRINT") {
			if (st.empty())
				cout << "NONE\n";
			else
				cout << st.top() << endl;
		}
		else {
			int n;
			cin >> n;
			st.push(n);
		}
	}	

	return 0;
}