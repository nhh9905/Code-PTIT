#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SinhVien {
	private:
		string id, ten, lop, ns;
		double gpa;
	public:
		void nhap();
		void xuat();
};
void SinhVien::nhap() {
	this->id = "B20DCCN001";
	getline(cin, this->ten);
	cin >> this->lop >> this->ns >> this->gpa;
}
void SinhVien::xuat() {
	int dem = 0;
	cout << this->id << " " << this->ten << " " << this->lop << " ";
	for (int i = 0; i < this->ns.size(); i++) {
		if (this->ns[i] != '/')
			++dem;
		else {
			if (dem == 1)
				this->ns.insert(i - 1, "0");
			dem = 0;
		}
	}
	cout << this->ns << " " << fixed << setprecision(2) << this->gpa;
}
int main() {
//	freopen("a.inp", "r", stdin);
	SinhVien a;
	a.nhap();
	a.xuat();
}
