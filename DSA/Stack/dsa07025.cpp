#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
string s;

void solve(string s) {
	stack<ll> st;

	stringstream ss(s);
	string tmp;
	vector<string> v;

	while (ss >> tmp) {
		v.push_back(tmp);
	}

	for (string str:v) {
		if (str != "+" && str != "-" && str != "*" && str != "/") {
			st.push(stoll(str));
		}

		else {
			ll x = st.top(); st.pop();
			ll y = st.top(); st.pop();
			ll kq;

			if (str == "*") {
				kq = x*y;
				st.push(kq);
			}

			if (str == "+") {
				kq = x + y;
				st.push(kq);
			}

			if (str == "-") {
				kq = y - x;
				st.push(kq);
			}

			if (str == "/") {
				kq = y / x;
				st.push(kq);
			}
		}
	}

	cout << st.top() << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		cin.ignore();
		getline(cin >> ws, s);
		solve(s);
	}

	return 0;
}