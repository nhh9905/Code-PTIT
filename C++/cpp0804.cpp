#include <bits/stdc++.h>
using namespace std;
int main() {
	fstream inp("VANBAN.in");
	string s;
	set<string> st;
	while (getline(inp, s)) {
		stringstream ss(s);
		string tmp;
		while (ss >> tmp) {
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
			st.insert(tmp);
		}
	}
	for (auto x:st)
		cout << x << endl;
	inp.close();
}
