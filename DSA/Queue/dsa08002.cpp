#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n;
	cin >> n;
	queue<int> q;

	while (n--) {
		string s;
		cin >> s;

		if (s == "PUSH") {
			int k;
			cin >> k;
			q.push(k);
		}

		if (s == "POP") {
			if (!q.empty())
				q.pop();
		}

		if (s == "PRINTFRONT") {
			if (!q.empty())
				cout << q.front() << endl;
			else
				cout << "NONE\n";
		}
	}	

	return 0;
}