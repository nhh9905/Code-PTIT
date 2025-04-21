#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sinh(string &s) {
	int i = s.size() - 1;
	while (i >= 0 && s[i] == '0')
		--i;
	if (i < 0) {
		for (int i = 0; i < s.size(); i++)
			s[i] = '1';
	}
	else {
		s[i] = '0';
		for (int j = i + 1; j < s.size(); j++)
			s[j] = '1';
	}
}

int main() {
	// freopen("a.inp", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		sinh(s);
		cout << s << endl;
	}	
	return 0;
}