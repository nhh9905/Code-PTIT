#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inp("DATA.in");
	int n;
	map<int, int> cnt;
	while (inp >> n)
		++cnt[n];
	inp.close();
	for (auto x:cnt) {
		cout << x.first << " " << x.second << endl;
	}
}
