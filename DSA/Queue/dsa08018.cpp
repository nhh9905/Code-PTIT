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
		queue<string> q;
		vector<string> v;

		q.push("6");
		q.push("8");
		while (!q.empty()) {
			if (q.front().size() > n) {
				break;
			}
			v.push_back(q.front());
			q.push(q.front() + "6");
			q.push(q.front() + "8");
			q.pop();
		}

		cout << v.size() << endl;
		for (string x:v)
			cout << x << " ";

		cout << endl;
	}	

	return 0;
}