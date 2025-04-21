#include <bits/stdc++.h>
using namespace std;
typedef struct People {
	string name, birth;
} People;
int year(People x) {
	string tmp;
	tmp.append(x.birth, 6, 4);
	return stoi(tmp);
}
int month(People x) {
	string tmp;
	tmp.append(x.birth, 3, 2);
	return stoi(tmp);
}
int day(People x) {
	string tmp;
	tmp.append(x.birth, 0, 2);
	return stoi(tmp);
}
bool cmp(const People &a, const People &b) {
	if (year(a) == year(b)) {
		if (month(a) == month(b)) {
			return day(a) > day(b);
		}
		else
			return month(a) > month(b);
	}
	else
		return year(a) > year(b);
}
int main() {
//	freopen("a.inp", "r", stdin);
	int n;
	cin >> n;
	People x[n];
	for (int i = 0; i < n; i++)
		cin >> x[i].name >> x[i].birth;
	sort(x, x + n, cmp);
	cout << x[0].name << endl << x[n - 1].name;
}
