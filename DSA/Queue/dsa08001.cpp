#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		queue<int> q;

		while (n--) {
			int choice;
			cin >> choice;
			if (choice == 1)
				cout << q.size() << endl;
			if (choice == 2) {
				if (q.empty())
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			if (choice == 3) {
				int k;
				cin >> k;
				q.push(k);
			}
			if (choice == 4) {
				if (!q.empty())
					q.pop();
			}
			if (choice == 5) {
				if (!q.empty())
					cout << q.front() << endl;
				else
					cout << "-1\n";
			}
			if (choice == 6) {
				if (!q.empty())
					cout << q.back() << endl;
				else
					cout << "-1\n";
			}
		}
	}	

	return 0;
}