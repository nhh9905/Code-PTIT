#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string s) {
	if (s.size() > 10)
		return 0;
	for (char x:s) {
        if (x < '0' && x > '9')
            return 0;
	}
	return 1;
}
int main() {
    ll ans = 0;
    ifstream inp("DATA.in");
    string s;
    while (getline(inp, s)) {
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
			if (check(tmp)) {
				ans += atoi(tmp.c_str());
			}
        }
    }
    cout << ans;
    inp.close();
}
