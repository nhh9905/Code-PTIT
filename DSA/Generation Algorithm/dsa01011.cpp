#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sinh(string s) {
	int i = s.size() - 2;
	while (i >= 0 && s[i] >= s[i + 1])
		--i;
	if (i < 0)
		cout << "BIGGEST\n";
	else {
		int j = s.size() - 1;
		while (s[i] >= s[j])
			--j;
		swap(s[i], s[j]);
		reverse(s.begin() + i + 1, s.end());
		cout << s << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		cout << n << " ";
		sinh(s);
	}

	return 0;
}