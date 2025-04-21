#include <bits/stdc++.h>
#define ll long long
using namespace std;
class NhanVien {
	private:
		string id, ten, gt, ngaySinh, dc, mst, ngayKy;
	public:
		friend istream& operator >> (istream &in, NhanVien &a);
		friend ostream& operator >> (ostream &out, NhanVien a);
};
istream& operator >> (istream &in, NhanVien &a) {
	a.id = "00001";
	getline(in, a.ten);
	in >> a.gt >> a.ngaySinh;
	in.ignore();
	getline(in, a.dc);
	in >> a.mst >> a.ngayKy;
	return in;
}
ostream& operator >> (ostream &out, NhanVien a) {
	out << a.id << " " << a.ten << " " << a.gt << " " << a.ngaySinh << " " << a.dc << " " << a.mst << " " << a.ngayKy;
	return out;
}
int main() {
//	freopen("a.inp", "r", stdin);
	NhanVien a;
	cin >> a;
	cout >> a;
	return 0;
}
