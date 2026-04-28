#include <bits/stdc++.h>
using namespace std;
int n, x[105], c[105][105], Cmin = INT_MAX, dem = 0;
bool visited[105];
int cost = 0, Fopt = INT_MAX;
vector<vector<int>> v(105);
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!visited[j]) {
			x[i] = j;
			cost += c[x[i - 1]][x[i]];
			visited[j] = 1;
			if (i == n) {
                if (cost + c[x[n]][1] < Fopt) {
				    Fopt = cost + c[x[n]][1];
                    for (int i = dem - 1; i >= 0; i--)
                        v[i].clear();
                    dem = 0;
                    for (int i = 1; i <= n; i++)
                        v[dem].push_back(x[i]);
                    ++dem;
                }
                else if (cost + c[x[n]][1] == Fopt) {
                    for (int i = 1; i <= n; i++)
                        v[dem].push_back(x[i]);
                    ++dem;
                }
            }
			else if (cost + (n - i + 1) * Cmin < Fopt)
				Try(i + 1);
			visited[j] = 0;
			cost -= c[x[i - 1]][x[i]];
		}
	}
}
int main() {
	freopen("a.inp", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
            if (c[i][j])
                Cmin = min(Cmin, c[i][j]);
		}
	}
	memset(visited, 0, sizeof(visited));
	x[1] = 1;
	visited[1] = 1;
	Try(2);
	cout << "Fopt = " << Fopt << endl << "Xopt = ";
	for (int i = 0; i < dem; i++) {
		if (i)
            cout << "       ";
		for (auto x:v[i])
        	cout << x << " ";
		cout << endl;
	}
}