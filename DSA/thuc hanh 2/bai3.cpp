#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;

ll calc(ll a, ll b, char c) {
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	return a / b;
}

bool check(string s) {
	if (s.empty())
		return 0;
	
	bool dau = 0;
	if (s[0] == '-')
		dau = 1;
	if (dau && s.size() == 1)
		return 0;
	
	for (int i = dau; i < s.size(); i++) {
		if (!isdigit(s[i]))
			return 0;
	}
	return 1;
}

void prefix(vector<string> s) {
	stack<ll> st;

	for (int i = n - 1; i >= 0; i--) {
		if (check(s[i]))
			st.push(stoll(s[i]));
		else {
			char c = s[i][0];
			ll tmp1 = st.top(); st.pop();
			ll tmp2 = st.top(); st.pop();
			st.push(calc(tmp1, tmp2, c));
		}
	}

	cout << st.top() << endl;
}

void postfix(vector<string> s) {
	stack<ll> st;

	for (int i = 0; i < n; i++) {
		if (check(s[i]))
			st.push(stoll(s[i]));
		else {
			char c = s[i][0];
			ll tmp1 = st.top(); st.pop();
			ll tmp2 = st.top(); st.pop();
			st.push(calc(tmp2, tmp1, c));
		}
	}

	cout << st.top() << endl;
}

void solve(vector<string> s) {
	char c = s[n - 1][0];
	if (c == '+' || c == '-' || c == '*' || c == '/')
		postfix(s);
	else
		prefix(s);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;

	while (t--) {
		string str, tmp;
		cin >> n;
		cin.ignore();
		getline(cin >> ws, str);

		stringstream ss(str);
		vector<string> v;

		while (ss >> tmp)
			v.push_back(tmp);
		
		solve(v);
	}

	return 0;
}