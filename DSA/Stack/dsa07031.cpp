#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
string s;

ll calc(ll a, ll b, string s) {
	if (s == "+")
		return a + b;
	if (s == "-")
		return a - b;
	if (s == "*")
		return a * b;
	if (s == "/")
		return a / b;
	return 0;
}

bool checkDigit(string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/")
		return 0;
	return 1;
}

void solve(string s) {
	stack<ll> st;
	stack<string> st1;

	stringstream ss(s);
	vector<string> v;

	string tmp;

	while (ss >> tmp) {
		v.push_back(tmp);
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		if (checkDigit(v[i])) {
			st.push(stoll(v[i]));
		}
		else {
			ll x = st.top(); st.pop();
			ll y = st.top(); st.pop();
			ll kq = calc(x, y, v[i]);
			st.push(kq);
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