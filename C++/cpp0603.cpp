#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SinhVien {
	private:
		string id, ten, lop, ns;
		double gpa;
	public:
		friend istream& operator >> (istream &in, SinhVien &a);
		friend ostream& operator << (ostream &out, SinhVien a);
};
istream& operator >> (istream &in, SinhVien &a) {
	a.id = "B20DCCN001";
	getline(in, a.ten);
	in >> a.lop >> a.ns >> a.gpa;
	return in;
}
ostream& operator << (ostream &out, SinhVien a) {
	int dem = 0;
	out << a.id << " ";
    stringstream ss(a.ten);
    string tmp;
    while (ss >> tmp) {
        cout << (char)toupper(tmp[0]);
        for (int i = 1; i < tmp.size(); i++)
            cout << (char)tolower(tmp[i]);
        cout << " ";
    }
    out << a.lop << " ";
	for (int i = 0; i < a.ns.size(); i++) {
		if (a.ns[i] != '/')
			++dem;
		else {
			if (dem == 1)
				a.ns.insert(i - 1, "0");
			dem = 0;
		}
	}
	out << a.ns << " " << fixed << setprecision(2) << a.gpa;
	return out;
}
int main() {
	// freopen("a.inp", "r", stdin);
	SinhVien a;
	cin >> a;
	cout << a;
    return 0;
}