#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int n;
	cin >> n;
	deque<int> q;

	while (n--) {
		string s;
		cin >> s;

		if (s == "PUSHBACK" || s == "PUSHFRONT") {
			int k;
			cin >> k;

			if (s == "PUSHBACK")
				q.push_back(k);
			else
				q.push_front(k);
		}

		if (s == "PRINTFRONT") {
			if (!q.empty())
				cout << q.front() << endl;
			else
				cout << "NONE\n";
		}

		if (s == "PRINTBACK") {
			if (!q.empty())
				cout << q.back() << endl;
			else
				cout << "NONE\n";
		}

		if (s == "POPFRONT") {
			if (!q.empty())
				q.pop_front();
		}

		if (s == "POPBACK") {
			if (!q.empty())
				q.pop_back();
		}
	}	

	return 0;
}