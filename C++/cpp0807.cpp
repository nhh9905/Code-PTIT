#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inp("DATA.in");
	int n, m;
	inp >> n >> m;
	set<int> st1, st2;
	for (int i = 0; i < n; i++) {
		int x;
		inp >> x;
		st1.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		inp >> x;
		if (st1.count(x))
			st2.insert(x);
	}
	inp.close();
	for (auto x:st2)
		cout << x << " ";
}

